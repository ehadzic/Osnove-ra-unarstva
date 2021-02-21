//TP 2016/2017 (Tutorijal 2, Zadatak 4)
//NAPOMENA: za ovaj zadatak je DOZVOLJENO prekopirati
//			prethodni i napraviti potrebne izmjene

#include <iostream>
#include <complex>
#include <cmath>
using std::cout;
using std::cin;
int main ()
{
    
    int n;
    std::complex <double> suma(0,0);
    double R,X;
    cout << "Unesite broj elemenata: " << std::endl;
    cin >> n;
     for(int i=1; i<=n; i++){
         cout << "R" << i << " = ";
         cin >> R;
         cout << "X" << i << " = ";
         cin >> X;
         cout << std::endl;
         suma= suma+(1./(std::complex<double>(R,X)));
     }
     
     
     cout << std::endl;
     cout << "Paralelna veza ovih elemenata ima R = "<< real(1./suma) << " i X = " << imag(1./suma) << ".";
     
	return 0;
}