//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

int main ()
{
 double n;
 int suma(0);
 while(1){ suma=0;
 cout << "Unesite prirodan broj ili 0 za kraj: ";
 cin>>n;

 while(n<0 || !(cin) || n!=int1(n)){
     cout<<"Niste unijeli prirodan broj!" << endl
     << "Unesite prirodan broj ili 0 za kraj: ";
      cin.clear();
    cin.ignore(1000, '\n');
     cin>>n;
 }
  if(int(n)==0){
     cout << "Dovidjenja!";
     return 0;
 }
 for(int i=1; i<n; i++){
     if(int(n)%i==0) suma=suma+i;
 }
 if(suma==int(n)) cout << "Broj " << n << " je savrsen!" << endl;
 else if(n>suma) cout << "Broj " << n << " je manjkav!" << endl;
 else if(n<suma) cout << "Broj " << n << " je obilan!" << endl;
 }
	return 0;
}