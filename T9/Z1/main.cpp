/*
    TP 16/17 (Tutorijal 9, Zadatak 1)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>



class Vektor3d
{
	
	double k[3];
public:
	void Postavi(double X, double Y, double Z) {
		Vektor3d::k[0]=X;
		
		Vektor3d::k[1]=Y;
		
		Vektor3d::k[2]=Z;

	}
	void PostaviX(double X) {
		
		Vektor3d::k[0]=X;

	}
	void PostaviY(double Y) {
		
		Vektor3d::k[1]=Y;
	}

	void PostaviZ(double Z) {
		
		Vektor3d::k[2]=Z;
		
	}
	void Ocitaj(double &X, double &Y, double &Z)const {
		X=Vektor3d::k[0];
		Y=Vektor3d::k[1];
		Z=Vektor3d::k[2];

	}

	void Ispisi()const {
		std::cout<<"{"<<k[0]<<","<<k[1]<<","<<k[2]<<"}";
	}

	double DajX() const {
		
		return k[0];
	}
	double DajY() const {
		
		return k[1];
	}
	double DajZ() const {
		
		return k[2];
	}
	double DajDuzinu() const {
		
		return std::sqrt(k[0]*k[0]+k[1]*k[1]+k[2]*k[2]);
	}

	Vektor3d &PomnoziSaSkalarom(double s) {
		k[0]*=s;
		
		k[1]*=s;
		
		k[2]*=s;
		
		return *this;
	}

	Vektor3d &SaberiSa(const Vektor3d &v) {
		k[0]+=v.k[0];
		
		k[1]+=v.k[1];
		
		k[2]+=v.k[2];
		
		return *this;
	}

	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};
Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
	Vektor3d v3;
	v3.k[0]=v1.k[0]+v2.k[0];
	
	v3.k[1]=v1.k[1]+v2.k[1];

	v3.k[2]=v1.k[2]+v2.k[2];
	return v3;
}


int main ()
{
	return 0;
}