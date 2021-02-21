/* 
    TP 16/17 (Tutorijal 11, Zadatak 1)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class NeobicnaKlasa{
	int element;
	public:
	explicit NeobicnaKlasa(int x):element(x){
		std::cout<<"Direktna inicijalizacija\n";
	}
	NeobicnaKlasa(double x):element(int(x)){
		std::cout<<"Kopirajuca inicijalizacija";
	}
};
int main ()
{
	NeobicnaKlasa X(2);
	NeobicnaKlasa Y=2;
	
	return 0;
}