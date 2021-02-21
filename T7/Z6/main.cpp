/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
using namespace std;
template<typename tip>
list <tip> SortirajListu(list<tip>&lista){
	for(auto i=lista.begin();i!=lista.end();i++)
	for(auto j=i; j!=lista.end();j++)
	if(*i>*j){
		tip temp=*j;
		*j=*i;
		*i=temp;
	}
	return lista;
}
int main ()
{
	cout<<"Koliko ima elemenata: ";
	int br_el;
	cin>>br_el;
	list<int>lista;
	cout<<"Unesite elemente: ";
	for(int i=0; i<br_el; i++){
		int a;
		cin>>a;
		lista.push_back(a);
	}
	
	cout<<"Sortirana lista: ";
	auto a=SortirajListu(lista);
	
	
	for(auto x: a) cout << x <<" ";
	
	return 0;
}