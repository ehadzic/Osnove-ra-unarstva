/*
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

class Tim
{
	char ime_tima[21];
	int broj_odigranih, broj_pobjeda, broj_nerijesenih, broj_poraza, broj_datih, broj_primljenih, broj_poena;
public:
	Tim(const char ime[]);
	void ObradiUtakmicu(int broj_datih, int broj_primljenih) {
		if(broj_datih<0 || broj_primljenih<0) throw range_error("Neispravan broj golova");
		Tim::broj_datih+=broj_datih;
		Tim::broj_primljenih+=broj_primljenih;
		int razlika(broj_datih-broj_primljenih);
		if(razlika>0) {
			broj_pobjeda++;
			broj_poena+=3;
		} else if(razlika==0) {
			broj_nerijesenih++;
			broj_poena++;
		} else broj_poraza++;
		broj_odigranih++;
	}

	const char *DajImeTima() const {
		return ime_tima;
	}

	int DajBrojPoena() const {
		return broj_poena;
	}
	int DajGolRazliku() const {
		return (broj_datih-broj_primljenih);
	}
	void IspisiPodatke() const {
		cout<<setw(20)<<left<<ime_tima;
		cout<<setw(4)<<right<<broj_odigranih;
		cout<<setw(4)<<right<<broj_pobjeda;
		cout<<setw(4)<<right<<broj_nerijesenih;
		cout<<setw(4)<<right<<broj_poraza;
		cout<<setw(4)<<right<<broj_datih;
		cout<<setw(4)<<right<<broj_primljenih;
		cout<<setw(4)<<right<<broj_poena<<endl;

	}
};


Tim::Tim(const char ime[])
{
	if(strlen(ime)>20) throw range_error("Predugacko ime tima");
    strcpy(ime_tima,ime);
	broj_odigranih=broj_pobjeda=broj_nerijesenih=broj_poraza=broj_datih=broj_primljenih=broj_poena=0;
}





int main ()
{
try{
	
	Tim tim1("Sarajevo");
	int a=tim1.DajBrojPoena();
	
}catch(...){
	cout<<"Greska";
}

return 0;
}