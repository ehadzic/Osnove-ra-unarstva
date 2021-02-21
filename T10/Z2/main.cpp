/* 
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>

using namespace std;
class Krug{
	double poluprecnik;
	public:
	explicit Krug(double r){
		if(r<=0) throw domain_error("Neispravan poluprecnik");
		Krug::poluprecnik=r;
	}
	void Postavi (double r){
		if(r<=0 ) throw domain_error("Neispravan poluprecnik");
		Krug::poluprecnik=r;
	}
	const double DajPoluprecnik ()const{
		return Krug::poluprecnik;
	}
	
	const double DajObim ()const{
		return 2*Krug::poluprecnik*4*atan(1.);
	}
	
	const double DajPovrsinu ()const{
		return Krug::poluprecnik*Krug::poluprecnik*4*atan(1.);
	}
	
	void Skaliraj(double faktor_skaliranja){
		if(faktor_skaliranja<=0) throw domain_error("Neispravan faktor skaliranja");
		Krug::poluprecnik=Krug::poluprecnik*faktor_skaliranja;
	}
	
	const void Ispisi() const{
		cout<<"R="<<DajPoluprecnik()<<fixed<<setprecision(5)<<" O="<<DajObim()
		<<fixed<<setprecision(5)<<" P="<<DajPovrsinu();
		
	}
	
};


class Valjak{
double visina; Krug baza;
public:
explicit Valjak(double b, double v):baza(b){
	if(b<0) throw domain_error("Neispravan poluprecnik");
	if(v<0) throw domain_error("Neispravna visina");
	this->baza=Krug(b);
	this->visina=v;
	
}
void Postavi (double b, double v){
	if(b<0) throw domain_error("Neispravan poluprecnik");
	if(v<0) throw domain_error("Neispravna visina");
	this->baza=Krug(b);
	this->visina=v;
}


const Krug DajBazu()const{
	return this->baza;
}

const double DajPoluprecnikBaze()const{
	return this->baza.DajPoluprecnik();
}


const double DajVisinu() const{
	return visina;
}

const double DajPovrsinu()const{
	return (2*this->baza.DajPovrsinu()+this->visina*this->baza.DajObim());
}


const double DajZapreminu()const{
	return (this->visina*this->baza.DajPovrsinu());
}

void Skaliraj(double faktor_skaliranja){
	if(faktor_skaliranja<=0) throw domain_error("Neispravan faktor skaliranja");
	this->baza.Skaliraj(faktor_skaliranja);
	this->visina=visina*faktor_skaliranja;
}

const void Ispisi() const{
	cout<<fixed<<setprecision(5)<<"R="<<DajPoluprecnikBaze()<<" H="<<DajVisinu()<< " P="<<DajPovrsinu()<<" V="<<DajZapreminu();
}
	
};

int main ()
{
	return 0;
}