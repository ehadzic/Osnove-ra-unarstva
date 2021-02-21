/* 
    TP 16/17 (Tutorijal 7, Zadatak 3)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <algorithm>
using namespace std;

int main ()
{
	int brrecenica;
	cout<<"Koliko zelite recenica: ";
	cin>>brrecenica;
	
	cin.ignore(1000, '\n');
	
	string ** recenice=nullptr;
	try{
		cout<<"Unesite recenice:"<<endl;
		recenice=new string*[brrecenica];
		for(int i=0; i<brrecenica; i++){
			
			recenice[i]=new string;
			getline(cin,*recenice[i]);
		}
		sort(recenice,recenice+brrecenica, [](string*a, string*b) { 
		return *a<*b;});
				
			cout<<"Sortirane recenice:"<<endl;
		for(int i=0; i<brrecenica;i++) cout<<*recenice[i]<<endl;
		
		for(int i=0; i<brrecenica;i++) delete recenice[i];
		delete [] recenice;
		
	}
	catch(...){
		cout<<"Problemi s memorijom!"<<endl;
		delete [] recenice;
		
	}
	
	
	return 0;
}