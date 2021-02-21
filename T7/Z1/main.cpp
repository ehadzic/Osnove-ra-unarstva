/* 
    TP 16/17 (Tutorijal 7, Zadatak 1)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

int main ()
{
	int brrecenica;
	cout<<"Koliko zelite recenica: ";
	cin>>brrecenica;
	
	cin.ignore(1000, '\n');
	
	char ** recenice=nullptr;
	try{
		cout<<"Unesite recenice:"<<endl;
		recenice=new char*[brrecenica];
		for(int i=0; i<brrecenica; i++){
			char radniprostor[1000];
			cin.getline(radniprostor, sizeof radniprostor);
			recenice[i]=new char[strlen(radniprostor)+1];
			strcpy(recenice[i],radniprostor);
		}
		for(int i=0;i<brrecenica;i++)
			for(int j=i; j<brrecenica;j++)
				if(strcmp(recenice[i],recenice[j])>=0) swap(recenice[i],recenice[j]);
				
		cout<<"Sortirane recenice:"<<endl;
		for(int i=0; i<brrecenica;i++) cout<<recenice[i]<<endl;
		
		for(int i=0; i<brrecenica;i++) delete [] recenice[i];
		delete [] recenice;
				
			
		
	}
	catch(...){
		cout<<"Problemi s memorijom!"<<endl;
		delete [] recenice;
		
	}
	
	
	return 0;
}