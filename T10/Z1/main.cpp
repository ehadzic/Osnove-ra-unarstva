/* 
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun{
	double s;
	public:
	StedniRacun(){s=0;}
	StedniRacun(double r){
		if(r<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		s=r;
	}
	
	void Ulozi(double suma){
		if((s+suma)<0) throw std::logic_error("Transakcija odbijena");
		s=s+suma;
	}
	
	void Podigni(double suma){
		if(suma>s) throw std::logic_error("Transakcija odbijena");
		s=s-suma;
	}
	double DajStanje()const{
		return s;
	}
	
	void ObracunajKamatu(double kamatna_stopa){
		if(kamatna_stopa<0) throw std::logic_error("Nedozvoljena kamatna stopa");
		double kamata;
		kamata=(s*kamatna_stopa)/100;
		s=s+kamata;
	}
};


int main ()
{
	return 0;
}