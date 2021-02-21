/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 2)
	
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
#include <deque>
template <typename x, typename y>
y RazmijeniBlokove(x p1, x p2, y p3){
	auto tmp=*p1;
	while(p1<p2){
		tmp=*p3;
		*p3=*p1;
		*p1=tmp;
		p1++;
		p3++;
	}
	return p3;
}

int main ()
{
	int a[]{1,2,3,4,5};
	int b[]{6,7,8,9,10};
	char c[]{"Jabuke"};
	char d[]{"Kruske"};
	RazmijeniBlokove(a,a+5,b);
	RazmijeniBlokove(c,c+6,d);
	std::cout<<c<<" "<<d<<std::endl;
	std::cout<<*a;
	return 0;
}