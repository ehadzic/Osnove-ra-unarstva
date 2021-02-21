/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 7)
	
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
#include <stdexcept>
#include <algorithm>
#include <deque>

template <typename tip1>
auto SumaBloka (tip1 start, tip1 end)->decltype(*start + *start){
	if(start==end) throw std::range_error("Blok je prazan");
	auto suma(*start++);
	while(start!=end){
		suma+=*start;
		start++;
	}
	return suma;
}
int main ()
{
	std::deque<int>d{1,2,3};
	std::cout<<SumaBloka(d.begin(), d.end());
	
	return 0;
}