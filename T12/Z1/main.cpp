/*
    TP 16/17 (Tutorijal 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
using namespace std;

class Sat
{
	int sati,minute,sekunde;
public:
	Sat(int h, int m, int s) {
		if(s>59) {
			while(s>59) {
				s=s-60;
				m++;
			}
		}

		if(s<0) {
			while(s<0) {
				s=s+60;
				m--;
			}
		}


		if(m>59) {
			while(m>59) {
				m=m-60;
				h++;
			}
		}

		if(m<0) {
			while(m<0) {
				m=m+60;
				h--;
			}
		}


		if(h>23) {
			while(h>23) {
				h=h-24;
			}
		}

		if(h<0) {
			while(h<0) {
				h=h+24;
			}
		}

		sati=h;
		minute=m;
		sekunde=s;
	}

	Sat() {
		sati=0;
		minute=0;
		sekunde=0;
	}

	static bool DaLiJeIspravno (int h, int m, int s) { //static jer vrijedi za svaku fju koja se pozove
		bool dobro_vrijeme=true;
		if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59)  dobro_vrijeme=false;
		return dobro_vrijeme;
	}

	void Postavi (int h, int m , int s) {
		if(DaLiJeIspravno(h,m,s)==false) throw std::domain_error("Neispravno vrijeme");
		sati=h;
		minute=m;
		sekunde=s;
	}

	void PostaviNormalizirano(int h, int m, int s) {

		if(s>59) {
			while(s>59) {
				s=s-60;
				m++;
			}
		}

		if(s<0) {
			while(s<0) {
				s=s+60;
				m--;
			}
		}


		if(m>59) {
			while(m>59) {
				m=m-60;
				h++;
			}
		}

		if(m<0) {
			while(m<0) {
				m=m+60;
				h--;
			}
		}


		if(h>23) {
			while(h>23) {
				h=h-24;
			}
		}

		if(h<0) {
			while(h<0) {
				h=h+24;
			}
		}

		sati=h;
		minute=m;
		sekunde=s;
	}

	friend Sat operator ++(Sat &sat, int) { //postfiksni
		Sat novi(sat);
		sat.sekunde++;
		sat.PostaviNormalizirano(sat.sati,sat.minute,sat.sekunde);
		return novi;
	}

	friend Sat &operator ++(Sat &sat) { //prefiksni
		sat.sekunde++;
		sat.PostaviNormalizirano(sat.sati,sat.minute,sat.sekunde);
		return sat;
	}

	friend Sat &operator -- (Sat &sat) { 
		sat.sekunde--;
		sat.PostaviNormalizirano(sat.sati,sat.minute,sat.sekunde);
		return sat;
	}

	friend Sat operator -- (Sat &sat, int) { 
		Sat novi(sat);
		sat.sekunde--;
		sat.PostaviNormalizirano(sat.sati,sat.minute,sat.sekunde);
		return novi;
	}

	friend Sat operator += (Sat &sat, int n) {
		sat.sekunde+=n;
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return sat;
	}

	friend Sat operator -= (Sat &sat, int n) {
		sat.sekunde-=n;
		sat.PostaviNormalizirano(sat.sati, sat.minute, sat.sekunde);
		return sat;
	}

	friend int operator -(const Sat &s1, const Sat &s2) {
		return ((s1.sati*3600+s1.minute*60+s1.sekunde)-(s2.sati*3600+s2.minute*60+s2.sekunde));
	}

	friend int operator +(const Sat &s1, const Sat &s2) {
		return ((s1.sati*3600+s1.minute*60+s1.sekunde)+(s2.sati*3600+s2.minute*60+s2.sekunde));
	}

	friend Sat operator +(Sat &s1, int n) {
		Sat novi;
		novi.sekunde=s1.sekunde+n;
		novi.minute=s1.minute;
		novi.sati=s1.sati;
		novi.PostaviNormalizirano(novi.sati, novi.minute, novi.sekunde);
		return novi;
	}

	friend Sat operator -(const Sat &s1, int n) {
		Sat novi;
		novi.sekunde=s1.sekunde-n;
		novi.minute=s1.minute;
		novi.sati=s1.sati;
		novi.PostaviNormalizirano(novi.sati, novi.minute, novi.sekunde);
		return novi;
	}


	int DajSate() const {
		return sati;
	}

	int DajMinute() const {
		return minute;
	}

	int DajSekunde() const {
		return sekunde;
	}

	friend std::ostream  &operator << (std::ostream &znak, const Sat &sat) {
		if(sat.sati<10 && sat.minute<10 && sat.sekunde<10) return znak<<"0"<<sat.sati<<":"<<"0"<<sat.minute<<":"<<"0"<<sat.sekunde;
		else if(sat.sati<10 && sat.minute>9 && sat.sekunde>9) return znak<<"0"<<sat.sati<<":"<<sat.minute<<":"<<sat.sekunde;
		else if(sat.sati>9 && sat.minute<10 && sat.sekunde>9) return znak<<sat.sati<<":"<<"0"<<sat.minute<<":"<<sat.sekunde;
		else if(sat.sati>9 && sat.minute>9 && sat.sekunde<10) return znak<<sat.sati<<":"<<sat.minute<<":"<<"0"<<sat.sekunde;
		else if(sat.sati<10 && sat.minute>9 && sat.sekunde<10) return znak<<"0"<<sat.sati<<":"<<sat.minute<<":"<<"0"<<sat.sekunde;
		else if(sat.sati<10 && sat.minute<10 && sat.sekunde>9) return znak<<"0"<<sat.sati<<":"<<"0"<<sat.minute<<":"<<sat.sekunde;
		else if(sat.sati>9 && sat.minute<10 && sat.sekunde<10) return znak<<sat.sati<<":"<<"0"<<sat.minute<<":"<<"0"<<sat.sekunde;
		else if(sat.sati>9 && sat.minute>9 && sat.sekunde>9) return znak<<sat.sati<<":"<<sat.minute<<":"<<sat.sekunde;
	}


	friend int BrojSekundiIzmedju(const Sat &s1 ,const Sat &s2);
	static int Razmak(const Sat &s1, const Sat &s2) {
		int sekunde1=s1.sekunde+s1.minute*60+s1.sati*3600;
		int sekunde2=s2.sekunde+s2.minute*60+s2.sati*3600;
		return sekunde1-sekunde2;
	}

};

int BrojSekundiIzmedju(const Sat &s1,const Sat &s2)   //ne treba sat:: jer je friend
{
	int sekunde1=s1.sekunde+s1.minute*60+s1.sati*3600;
	int sekunde2=s2.sekunde+s2.minute*60+s2.sati*3600;
	return sekunde1-sekunde2;
}

int main ()
{
	Sat sat1(10, 10, 10);
	Sat sat2(20, 20, 20);
	sat1+=5;
	cout << sat1 << endl;
	sat1--;
	cout<<sat1<<endl;
	return 0;
}