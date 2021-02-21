/* 
    TP 2016/2017 (Tutorijal 5, Zadatak 6)
	
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
#include <vector>
#include <cmath>
#include <string>

int sumaStr(std::string s, int n){
	static int ret(0);
	if(n==0){
		int tmp(ret);
		ret=0;
		return tmp;
	}
	ret+=s[n-1]-'0';
	s.resize(n-1);
	return (sumaStr(s,n-1));
}

int sumaCif(int x){
	if(x==0) x=1;
	
	int n=int(std::log10(std::abs(x)))+1;
	std::string broj=std::to_string(std::abs(x));
	return sumaStr(broj,n);
}

bool veci(int x, int y){
	if(sumaCif(x)==sumaCif(y)) return x<y;
	return std::abs(sumaCif(x))<std::abs(sumaCif(y));
}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::vector<int>v(n);
	std::cout<<"Unesite elemente: ";
	std::for_each(v.begin(),v.end(), [](int &x){
		std::cin>>x;});
		std::cout<<"Niz sortiran po sumi cifara glasi: ";
		std::sort(v.begin(), v.end(), veci);
		std::for_each(v.begin(),v.end(), [](int &x){
		std::cout<<x<<" ";});
		std::cout<<std::endl<<"Unesite broj koji trazite: ";
		int find;
		std::cin>>find;
		//std::find(v.begin(), v.end(), find);
		if(std::find(v.begin(), v.end(), find)==v.end()){
			std::cout<<"Trazeni broj ne nalazi se u nizu!";
		}
		else{
			std::cout<<"Trazeni broj nalazi se na poziciji ";
			std::cout<<std::find(v.begin(), v.end(), find)-v.begin();
		}
	
	return 0;
}