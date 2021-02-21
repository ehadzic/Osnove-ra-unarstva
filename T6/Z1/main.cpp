/* 
    TP 16/17 (Tutorijal 6, Zadatak 1)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/

#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <iomanip>

template <typename nekoime>
nekoime *GenerirajStepeneDvojke (int n){
	nekoime x= std::numeric_limits<nekoime>::max();
	nekoime *p;
	if(std::pow<nekoime>(2, n-1)>x)
	throw std::overflow_error("Prekoracen dozvoljeni opseg");
	if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
	try{
		p=(new nekoime[n]);
		nekoime cur=1;
		for(int i=0; i<n; i++){
			if(cur>x || cur <0){
				delete [] p;
				throw std::overflow_error("Prekoracen dozvoljeni opseg");
				
			}
			p[i]=cur;
			cur=cur*2;
		}
	}catch(std::bad_alloc err){
		throw std::runtime_error("Alokacija nije uspjela");
	}
	return p;
}

int main ()
{
	std::cout<<"Koliko zelite elemenata: ";
	int n;
	std::cin>>n;
	try{
		long double *p=GenerirajStepeneDvojke<long double>(n);
		for(int i=0; i<n; i++){
			if(std::floor(p[i])==p[i])
			std::cout<<std::fixed<<std::setprecision(0)<<p[i]<< " ";
			else std::cout<<std::scientific<<std::setprecision(6)<<p[i]<<" ";
			
		}
		delete [] p;
	}catch(std::exception &err){
		std::cout<<"Izuzetak: "<<err.what();
	}
	
	return 0;
}