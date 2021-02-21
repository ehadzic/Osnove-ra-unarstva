#include <iostream>
#include <stdexcept>


class Sat
{
    int sat, min, sek;
public:
    static bool DaLiJeIspravno(int sat, int min, int sek) {
        if(sat>=0 && sat<=23 && min>=0 && min<=59 && sek>=0 && sek<=59) return true;
        return false;
    }
    void Postavi(int sat, int min, int sek) {
        if(DaLiJeIspravno(sat,min,sek)) Sat::sat = sat;
        Sat::min = min;
        Sat::sek = sek;
        if(!DaLiJeIspravno(sat,min,sek)) throw std::domain_error("Neispravno vrijeme");
    }
    void PostaviNormalizirano(int sat, int min, int sek);
    Sat Sljedeci() {
        sek++;
        Sat s1;
        PostaviNormalizirano(sat,min,sek);
        s1.PostaviNormalizirano(sat,min,sek);
        return s1;
    }
    Sat Prethodni() {
        sek--;
        Sat s1;
        PostaviNormalizirano(sat,min,sek);
        s1.PostaviNormalizirano(sat,min,sek);
        return s1;
    }
    Sat PomjeriZa(int x) {
        sek+=x;
        Sat s1;
        PostaviNormalizirano(sat,min,sek);
        s1.PostaviNormalizirano(sat,min,sek);
        return s1;
    }
    void Ispisi () const {
        if(sat<10 && min>9 && sek>9) std::cout << "0" << sat << ":" << min << ":" << sek;
        else if(sat>9 && min<10 && sek>9) std::cout << sat << ":0" << min << ":" << sek;
        else if(sat>9 && min>9 && sek<10) std::cout <<  sat << ":" << min << ":0" << sek;
        else if(sat<10 && min<10 && sek>9) std::cout << "0" << sat << ":0" << min << ":" << sek;
        else if(sat<10 && min>9 && sek<10) std::cout << "0" << sat << ":" << min << ":0" << sek;
        else if(sat>9 && min<10 && sek<10) std::cout << sat << ":0" << min << ":0" << sek;
        else if(sat<10 && min<10 && sek<10) std::cout << "0" << sat << ":0" << min << ":0" << sek;
        else if(sat>9 && min>9 && sek>9) std::cout << sat << ":" << min << ":" << sek;
    }
    int DajSekunde() const {
        return sek;
    }
    int DajMinute() const {
        return min;
    }
    int DajSate() const {
        return sat;
    }
    static int Razmak(const Sat &s1, const Sat &s2) {
        int brsec1,brsec2;
        brsec1=3600*s1.sat;
        brsec1+=60*s1.min;
        brsec1+=s1.sek;
        brsec2=3600*s2.sat;
        brsec2+=60*s2.min;
        brsec2+=s2.sek;
        return brsec1-brsec2;
    }
    friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2) {
        int brsec1,brsec2;
        brsec1=3600*s1.sat;
        brsec1+=60*s1.min;
        brsec1+=s1.sek;
        brsec2=3600*s2.sat;
        brsec2+=60*s2.min;
        brsec2+=s2.sek;
        return brsec1-brsec2;
    }

};

void Sat::PostaviNormalizirano(int sati, int minute, int sekunde)
{
    while(sekunde>59) {
        minute++;
        sekunde-=60;
    }
    while(sekunde<0) {
        minute--;
        sekunde+=60;
    }
    while(minute>59) {
        sati++;
        minute-=60;
    }
    while(minute<0) {
        sati--;
        minute+=60;
    }
    while(sati>23) {
        sati-=24;
    }
    while(sati<0) {
        sati+=24;
    }
    Sat::sat = sati;
    Sat::min = minute;
    Sat::sek = sekunde;
}

int main ()
{
    Sat s1, s2;
    s1.Postavi(10,10,10);
    s2.Postavi(10,10,15);
    std::cout << BrojSekundiIzmedju(s2, s1) << " " << Sat::Razmak(s2, s1) << std::endl;
    std::cout << BrojSekundiIzmedju(s1, s2) << " " << Sat::Razmak(s1, s2) << std::endl;
    s1.Postavi(13, 0, 0);
    s2.Postavi(15, 30, 3);
    std::cout << BrojSekundiIzmedju(s2, s1) << " "
              << Sat::Razmak(s2, s1) << std::endl;
    std::cout << BrojSekundiIzmedju(s1, s2) << " "
              << Sat::Razmak(s1, s2);
    return 0;
}