/*
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class ApstraktniStudent
{
	std::string ime, prezime;
	int indeks, polozeni;
	double prosjek;

public:
	ApstraktniStudent(std::string s1, std::string s2, int i):
		ime(s1), prezime(s2), indeks(i), polozeni(0), prosjek(5) {}
	string DajIme()const {return ime;}
	string DajPrezime()const {return prezime;}
	int DajBrojIndeksa()const {return indeks;}
	int DajBrojPolozenih()const {return polozeni;}
	double DajProsjek()const {return prosjek;}
	void RegistrirajIspit(int ocjena){
		if(ocjena==5) return;
		if(ocjena<5 || ocjena>10) throw domain_error("Neispravna ocjena");
		prosjek=(prosjek*polozeni+ocjena)/(polozeni+1);
		polozeni++;
	}
	void PonistiOcjene(){polozeni=0; prosjek=5;}
	virtual void IspisiPodatke() const=0;
	virtual ApstraktniStudent* DajKopiju() const=0;
	virtual ~ApstraktniStudent(){}
};

class StudentBachelor: public ApstraktniStudent{
	public:
	StudentBachelor(string s1, string s2, int i):ApstraktniStudent(s1,s2,i){}
	void IspisiPodatke() const override{
		cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<
		DajBrojIndeksa()<<",\nima prosjek "<<DajProsjek()<<".\n";
	}
	ApstraktniStudent *DajKopiju()const override{
		return new StudentBachelor(*this);
	}
	~StudentBachelor(){}
};

class StudentMaster:public ApstraktniStudent{
	int diplomirao;
	public:
	StudentMaster(string s1, string s2, int i, int godina):ApstraktniStudent(s1,s2,i), diplomirao(godina){}
	ApstraktniStudent *DajKopiju()const override{
		return new StudentMaster(*this);
	}
	void IspisiPodatke()const override{
		cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<
		DajBrojIndeksa()<<",\nzavrsio bachelor studij godine "<<diplomirao<<",ima prosjek "<<DajProsjek()<<".\n";
	}
	~StudentMaster(){}
};
int main ()
{
	StudentMaster student1("Enil", "Pajic", 18999, 2015);
	StudentBachelor student2("Semra", "Pajic", 18998);
	student1.IspisiPodatke();
	student2.IspisiPodatke();
	try{
		student1.RegistrirajIspit(10);
		student1.RegistrirajIspit(9);
		student1.RegistrirajIspit(10);
		
	}catch(...){}
	
	try{
		student2.RegistrirajIspit(10);
		student2.RegistrirajIspit(8);
	}catch(...){}
	
	student1.IspisiPodatke();
	student2.IspisiPodatke();
	return 0;
}