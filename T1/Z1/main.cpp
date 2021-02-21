//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
int main ()
{
    int a,b,c,d,suma(0);
    cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    cin >> a >> b >> c;
    cout << "Unesite sirinu plocice u centimetrima: " << endl;
    cin >> d;
    if((a*100)%d!=0 || (b*100)%d!=0 || (c*100)%d!=0) {
        cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c <<
             "m sa plocicama dimenzija " << d << "x" << d << "cm" << endl <<  "nije izvodljivo bez lomljenja plocica!";
        return 0;
    } else {
        int e=(a*100)/d;
        int f=(b*100)/d;
        int g=(c*100)/d;
        
        suma=(e*f)+2*e*g+2*f*g;
    }
    cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << 
    "m sa plocicama dimenzija " << d << "x" << d << "cm" << endl << "potrebno je " << suma << " plocica.";
        return 0;
}