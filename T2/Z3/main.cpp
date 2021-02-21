//TP 2016/2017 (Tutorijal 2, Zadatak 3)
//NAPOMENA: OBAVEZNO je koristenje <complex> biblioteke!
#include <iostream>
#include <complex>
#include <cmath>
using std::cout;
using std::cin;
int main ()
{
    
    int n;
    std::complex <double> suma(0,0);
    std::complex <double> z;
    cout << "Unesite broj elemenata: " << std::endl;
    cin >> n;
     for(int i=1; i<=n; i++){
         cout << "Z_" << i << " = ";
         cin >> z;
         suma= suma+(1./z);
     }
     
     
     cout << std::endl;
     cout << "Paralelna veza ovih elemenata ima impedansu Z_ = "<< 1./suma << ".";
     
	return 0;
}