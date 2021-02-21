/*
    TP 16/17 (Tutorijal 11, Zadatak 4)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include<iostream>
#include<cstring>
#include<iomanip>
#include<stdexcept>
#include<algorithm>
using namespace std;

class Tim
{
	char ime_tima[20];
	int broj_odigranih, broj_pobjeda, broj_nerijesenih, broj_poraza, broj_datih, broj_primljenih, broj_poena;
public:
	Tim(const char *ime) : broj_odigranih(0), broj_pobjeda(0), broj_nerijesenih(0), broj_poraza(0), broj_datih(0), broj_primljenih(0), broj_poena(0) {
		if(strlen(ime) > 19) throw range_error("Predugacko ime tima");
		strcpy(ime_tima, ime);
	}
	void ObradiUtakmicu(int broj_datih, int broj_primljenih);
	const char *DajImeTima() const {
		return ime_tima;
	}
	int DajBrojPoena() const {
		return broj_poena;
	}
	int DajGolRazliku() const {
		return broj_datih - broj_primljenih;
	}
	void IspisiPodatke() const {
		cout << setw(20) << left << ime_tima << right << setw(4) << broj_odigranih << setw(4) << broj_pobjeda << setw(4) << broj_nerijesenih << setw(4) << broj_poraza << setw(4) << broj_datih << setw(4) << broj_primljenih << setw(4) << broj_poena << std::endl;
	}
};

class Liga
{
	int broj_timova;
	const int max_br_timova;
	Tim **timovi;
public:
	explicit Liga(int);
	explicit Liga(initializer_list<Tim>);
	~Liga();
	Liga(const Liga &l);
	Liga(Liga &&l);
	Liga &operator =(const Liga &l);
	Liga &operator =(Liga &&l);
	void DodajNoviTim(const char *ime_tima);
	void RegistrirajUtakmicu(const char *tim1, const char *tim2, int rezultat_1, int rezultat_2);
	void IspisiTabelu();
};

void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih)
{
	if(broj_datih < 0 || broj_primljenih < 0)
		throw range_error("Neispravan broj golova");
	broj_odigranih++;
	Tim::broj_datih += broj_datih;
	Tim::broj_primljenih += broj_primljenih;
	if(broj_datih > broj_primljenih) {
		broj_pobjeda++;
		broj_poena += 3;
	} else if(broj_datih == broj_primljenih) {
		broj_nerijesenih++;
		broj_poena++;
	} else
		broj_poraza++;
}

Liga::Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(nullptr)
{
	timovi = new Tim*[max_br_timova];
	for(int i = 0; i < max_br_timova; i++)
		timovi[i] = nullptr;
}

Liga::Liga(initializer_list<Tim> lista_timova) : broj_timova(lista_timova.size()), max_br_timova(broj_timova), timovi(nullptr)
{
	initializer_list<Tim>::iterator it {lista_timova.begin()};
	timovi = new Tim*[broj_timova];
	for(int i = 0; i < broj_timova; i++)
		timovi[i] = nullptr;
	try {
		for(int i = 0; i < broj_timova; i++) {
			timovi[i] = new Tim(*it);
			it++;
		}
	} catch(...) {
		for(int i = 0; i < broj_timova; i++)
			delete timovi[i];
		delete[] timovi;
		throw;
	}
}

Liga::~Liga()
{
	for(int i = 0; i < max_br_timova; i++)
		delete timovi[i];
	delete[] timovi;
}

Liga::Liga(const Liga &l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(nullptr)
{
	timovi = new Tim*[max_br_timova];
	for(int i = 0; i < broj_timova; i++)
		timovi[i] = new Tim(*l.timovi[i]);
}

Liga::Liga(Liga &&l) : broj_timova(l.broj_timova), max_br_timova(l.max_br_timova), timovi(l.timovi)
{
	l.timovi = nullptr;
}

Liga& Liga::operator =(const Liga &l)
{
	if(max_br_timova != l.max_br_timova)
		throw logic_error("Nesaglasni kapaciteti liga");
	if(this == &l)
		return *this;
	for(int i = 0; i < broj_timova; i++)
		delete timovi[i];
	broj_timova = l.broj_timova;
	for(int i = 0; i < broj_timova; i++)
		timovi[i] = new Tim(l.timovi[i]->DajImeTima());
	return *this;
}

Liga& Liga::operator =(Liga &&l)
{
	if(max_br_timova != l.max_br_timova)
		throw logic_error("Nesaglasni kapaciteti liga");
	if(this == &l)
		return *this;
	timovi = l.timovi;
	l.timovi = nullptr;
	return *this;
}

void Liga::DodajNoviTim(const char *ime_tima)
{
	if(strlen(ime_tima) > 19)
		throw range_error("Predugacko ime tima");
	if(broj_timova == max_br_timova)
		throw range_error("Liga popunjena");
	for(int i = 0; i < broj_timova; i++)
		if(!strcmp(ime_tima, timovi[i]->DajImeTima()))
			throw logic_error("Tim vec postoji");
	timovi[broj_timova] = new Tim(ime_tima);
	broj_timova++;
}

void Liga::RegistrirajUtakmicu(const char *tim1, const char *tim2, int rezultat_1, int rezultat_2)
{
	int indeks1 = -1, indeks2 = -1;
	for(int i = 0; i < broj_timova; i++)
		if(!strcmp(tim1, timovi[i]->DajImeTima())) {
			indeks1 = i;
			break;
		}
	for(int i = 0; i < broj_timova; i++)
		if(!strcmp(tim2, timovi[i]->DajImeTima())) {
			indeks2 = i;
			break;
		}
	if(indeks1 == -1 || indeks2 == -1)
		throw logic_error("Tim nije nadjen");
	if(rezultat_1 < 0 || rezultat_2 < 0)
		throw range_error("Neispravan broj golova");
	timovi[indeks1]->ObradiUtakmicu(rezultat_1, rezultat_2);
	timovi[indeks2]->ObradiUtakmicu(rezultat_2, rezultat_1);

}

bool Sortiraj(Tim *prvi, Tim *drugi)
{
	if(prvi->DajBrojPoena() != drugi->DajBrojPoena())
		return prvi->DajBrojPoena() > drugi->DajBrojPoena();
	else if(prvi->DajGolRazliku() != drugi->DajBrojPoena())
		return prvi->DajGolRazliku() > drugi->DajBrojPoena();
	else
		return strcmp(prvi->DajImeTima(), drugi->DajImeTima()) == -1;
}

void Liga::IspisiTabelu()
{
	sort(timovi, timovi + broj_timova, Sortiraj);
	for(int i = 0; i < broj_timova; i++)
		timovi[i]->IspisiPodatke();
}
int main(){
	
	try{
		Liga LigaPrvaka(3);
        LigaPrvaka.DodajNoviTim("Velez");
        LigaPrvaka.DodajNoviTim("Barselona");
        LigaPrvaka.DodajNoviTim("Sarajevo");
        LigaPrvaka.RegistrirajUtakmicu("Sarajevo", "Velez", 3, 4);
        LigaPrvaka.IspisiTabelu();
	}    catch(std::range_error er1) {
        std::cout<<er1.what()<<std::endl;
    }
    catch(std::logic_error er2) {
        std::cout<<er2.what()<<std::endl;
    }
	return 0;
	
}