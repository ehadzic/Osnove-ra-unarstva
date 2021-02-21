/*
	TP 2016/2017 (Tutorijal 2, Zadatak 1)
	NAPOMENA: za Autotest 8 procitati dodatak 
			  "Prekoracenja i nepredznacna aritmetika"
	Link: https://c2.etf.unsa.ba/mod/resource/view.php?id=34456
	
	ZABRANJENA je svaka vrsta stimanja/hardkodiranja, posebno
	gdje se navode konstante, tipa if (x == 123)
*/
#include <iostream>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::vector;
bool DaLiJeProst(int n){
	int brojac=0;
	if(n<=1) return false;
	for(unsigned int i=2; i<=std::sqrt(n); i++){
		if(n%i==0) return false;
	}
	
	return true;
	
}

vector<int>ProstiBrojeviUOpsegu(int a, int b){
	vector <int> v;
	for(unsigned int i=a; ; i++){
		if(DaLiJeProst(i)==true) v.push_back(i);
		if(i==b) break;
	}
	
	return v;
}


int main ()
{
	int a,b;
	cout << "Unesite pocetnu i krajnju vrijednost: ";
	cin >> a >> b;
	vector<int>v=ProstiBrojeviUOpsegu(a,b);
	if(v.size()==0) cout << "Nema prostih brojeva u rasponu od " << a <<
	" do " << b << "!";
	else cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
	for(unsigned int i=0; i<v.size(); i++){
		if (i==v.size()-1) {cout << v.at(i) << std::endl;}
		else{ cout << v.at(i) << ", ";}
	}
	
	
	
	return 0;
}