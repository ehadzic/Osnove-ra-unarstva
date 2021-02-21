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
    const double PI(atan(1)*4);
    int n;
    std::complex <double> suma(0,0);
    double Z,fi;
    cout << "Unesi broj elemenata: " << std::endl;
    cin >> n;
     for(int i=1; i<=n; i++){
         cout << "Z" << i << " = ";
         cin >> Z;
         cout << "fi" << i << " = ";
         cin >> fi;
         cout << std::endl;
         suma= suma+(1./(std::polar(Z,(fi*PI)/180.)));
     }
     
     
     cout << "Paralelna veza ovih elemenata ima Z = "<< abs(1./suma) << " i fi = " << ((std::arg(1./suma))*180.)/PI << ".";
     
	return 0;
}