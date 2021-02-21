/*
    TP 16/17 (Tutorijal 6, Zadatak 4)

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <stdexcept>
int **KreirajTrougao(int n)
{
	if(n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	int cur(1);
	int**a;

	try {
		a=(new int*[n]);
		for(int i=0; i<n; i++) a[i]=nullptr;
		a[0]=new int [((2+(n-1)*2)*n)/2];
		for(int i=0; i<n; i++) {
			a[i]=a[i-1]+i*2-1;
		}
	} catch(...) {
		delete []a;
		throw std::bad_alloc();
	}
	for(int i=0; i<n; i++) { 
		for(int j=0; j<((i+1)*2-1)/2; j++) {
			a[i][j]=i+1-j;
			a[i][i*2-j]=i+1-j;
		}
		a[i][i]=1;
	}
	return a; 
}

int main ()
{
	std::cout<<"Koliko zelite redova: ";
	int n;
	bool noErr = true;
	int **a;
	std::cin>>n;
	try {
		a=(KreirajTrougao(n));
	} catch(std::domain_error err) {
		std::cout<<"Izuzetak: "<<err.what();
		noErr=false;
	} catch(...) {
		std::cout<<"Izuzetak: Nedovoljno memorije!";
		noErr=false;
	}
	if(noErr) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<(i+1)*2-1; j++) {
				std::cout<<a[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		delete[] a[0];
		delete a;
	}

	return 0;
}