/* TP 2016/2017 (Tutorijal 4, Zadatak 2)

   Autotestovi by Eldar Kurtic, sva pitanja, sugestije i prijave gresaka javite na 
   mail ekurtic3@etf.unsa.ba
   
   NAPOMENA: testovi ce biti konacni TEK pred pocetak tutorijala. Zbog toga pokrenite
   testove za SVE zadatke na tutorijalu, da se ne bi desila situacija da neko uradi
   zadatak ranije i prolazi mu npr. 5/5 testova a naknadno dodano jos 2 testa koja mu
   padaju!
   
*/

#include <iostream>
#include <string>

void IzvrniString(std::string &s){
char pom;
for(int i=0; i<=((int)s.size()/2);i++){
   pom=s.at(i);
   s.at(i)=s[s.size()-1-i];
   s[s.size()-1-i]=pom;
}
}

int main () 
{
   std::string s;
   std::cout<<"Unesi string: " << "Izvrnuti string je: "<<s;
   std::getline(std::cin,s);
   IzvrniString(s);
   std::cout<<s<<std::endl;
	return 0;
}