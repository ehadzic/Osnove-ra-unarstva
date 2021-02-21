/* TP 2016/2017 (Tutorijal 4, Zadatak 1)

   Autotestovi by Eldar Kurtic, sva pitanja, sugestije i prijave gresaka javite na 
   mail ekurtic3@etf.unsa.ba
   
   NAPOMENA: testovi ce biti konacni TEK pred pocetak tutorijala. Zbog toga pokrenite
   testove za SVE zadatke na tutorijalu, da se ne bi desila situacija da neko uradi
   zadatak ranije i prolazi mu npr. 5/5 testova a naknadno dodano jos 2 testa koja mu
   padaju!
   
*/
#include <iostream>

int Cifre(long long int n, int &c_min, int &c_max){
   if(n<0) n=n*(-1);
   
   if(n==0){
      c_min=0;
      c_max=0;
      return 1;
   }
   
   int c, brojac(0);
   c_min=n%10;
   c_max=n%10;
   
   while(n!=0){
      c=n%10;
      if(c<c_min) c_min=c;
      if(c>c_max) c_max=c;
      brojac++;
      n=n/10;
   }
   return brojac;
}

int main ()
{
   int a(0), b(0);
   long long int n;
   std::cout<<"Unesite broj: ";
   std::cin>>n;
   int e=Cifre(n,a,b);
   std::cout<<"Broj " << n <<" ima "<<e<<" cifara, najveca je " <<b<<" a najmanja "<<a<<".";
	return 0;
}