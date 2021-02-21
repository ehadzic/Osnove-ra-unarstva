/*
    TP 16/17 (Tutorijal 6, Zadatak 2)

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <type_traits>

template <typename nekoime>
auto KreirajIzvrnutiNiz(nekoime start, nekoime end)

	-> typename std::remove_reference<decltype(*start)>::type* {
		
	typedef typename std::remove_reference<decltype(*start)>::type xxx;
	int num(0);
	nekoime save(start);
	while(save!=end) {
		num++;
		save++;
	}
	xxx *p;
	try {
		p=(new xxx[num]);
	} catch(...) {
		throw std::bad_alloc();
	}
	xxx *klizi(p);
	while (end!=start) {
		num--;
		*(klizi+num)=*start;
		start++;

	}
	return p;
}

int main ()
{
	int n;
	std::cout<<"Koliko zelite elemenata: ";
	std::cin>>n;
	try {
		std::vector<double>v(n);
		std::cout<<"Unesite elemente: ";
		for(int i=0; i<n; i++) {
			std::cin>>v[i];
		}
		std::cout<<"Kreirani niz: ";
		auto pok(KreirajIzvrnutiNiz(v.begin(),v.end()));
		for(int i=0; i<n; i++) {
			std::cout<<pok[i]<<" ";
		}
		delete [] pok;
	} catch(...) {
		std::cout<<"Nedovoljno memorije!";
	}
	return 0;
}