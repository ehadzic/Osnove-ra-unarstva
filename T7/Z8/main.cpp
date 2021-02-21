/* 
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string IzvrniBezRazmaka(string s){
	string s1;
	remove_copy(s.rbegin(),s.rend(), back_inserter(s1), ' ');
	return s1;
	
}

int main ()
{
string s="Evo pada kiša.";
string s1=IzvrniBezRazmaka(s);
cout<<s1;

	
	return 0;
}