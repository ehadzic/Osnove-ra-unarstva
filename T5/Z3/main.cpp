/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 3)
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: autotestovi ce biti konacni TEK pred pocetak tutorijala,
	          odnosno mogu se do tada mijenjati, pa su studenti u toku
			  tutorijala duzni da ponovo testiraju SVE zadatke!
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <algorithm>
#include <cmath>

bool kvadrat (int x){
	double a;
	a=std::sqrt(x);
	if(a==int(a)) return true;
	return false;
}

void unesi (int &x){
	std::cin>>x;
}

int mincif(int x, int y){
	x=std::abs(x);
	y=std::abs(y);
	return int(std::log(x))<int(std::log(y));
}
int trcif (int x){
	return int (std::log10(std::abs(x)))+1==3;
}

int main ()
{
	int n, niz[1000];
	std::cout<<"Unesite broj elemenata (max. 1000): ";
	std::cin>>n;
	std::cout<<"Unesite elemente: ";
	std::for_each(niz, niz+n, unesi);
	int *max=std::max_element(niz,niz+n);
	std::cout<<"Najveci element niza je "<<*max<<std::endl;
	int *min=std::min_element(niz, niz+n);
	int brojac=std::count(niz, niz+n, *min);
	std::cout<<"Najmanji element niza se pojavljuje "<< brojac<<" puta u nizu"<<std::endl;
	int a=std::count_if(niz, niz+n, kvadrat);
	std::cout<<"U nizu ima "<<a<<" brojeva koji su potpuni kvadrati"<<std::endl;
	std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(niz,niz+n,mincif);
	int novi [1000];
	std::cout<<std::endl<<"Elementi koji nisu trocifreni su: ";
	int*z=std::remove_copy_if(niz, niz+n, novi, trcif);
	std::for_each(novi,z,[](int x){std::cout<<x<<" ";});
	return 0;
}