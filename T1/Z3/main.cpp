//TP 2016/2017: Tutorijal 1, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::setw;
using std::right;
using std::fixed;
using std::setprecision;

int main ()
{
 double a, b;
 cout << "Unesite pocetnu i krajnju vrijednost: " << endl;
 cin >> a >> b;
 if(int(a)<int(b) && int(a)<=9999 && int(b)<=9999 && a==int(a) && b==int(b)){
     cout << "+---------+----------+----------+-----------+" << endl;
     cout << "| Brojevi | Kvadrati | Korijeni | Logaritmi |" << endl;
     cout << "+---------+----------+----------+-----------+" << endl;
     for(int i=int(a); i<=int(b); i++){
         cout << "| " << left << setw(8) << i << "|" << right << setw(9) << i*i << " " << "|" <<
         right << setw(9) << fixed << setprecision(3) << sqrt(i) << " " << "|" << right << setw(10) <<
         fixed << setprecision(5) << log(i) << " " << "|" << endl;
         
     }
     cout << "+---------+----------+----------+-----------+";
     
 }
    
	return 0;
}