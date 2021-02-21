//TP 2016/2017: Tutorijal 8, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <iomanip>
struct Vrijeme{
  int sati, minute, sekunde;  
};

void TestirajVrijeme (const Vrijeme &v){
     if(v.sati>=24 || v.sati<0 || v.minute>59 || v.minute<0 || v.sekunde>59 || v.sekunde<0)
    throw std::domain_error("Neispravno vrijeme"); 
}

void IspisiVrijeme(const Vrijeme &v){
    TestirajVrijeme(v);
    std::cout<<std::setw(2)<<std::setfill('0')<<v.sati<<":"<<std::setw(2)<<std::setfill('0')<<v.minute<<":"<<
    std::setw(2)<<std::setfill('0')<<v.sekunde;
    
    
    
}

Vrijeme SaberiVrijeme(Vrijeme &v1, Vrijeme &v2){
    TestirajVrijeme(v1);
    TestirajVrijeme(v2);
    Vrijeme povratno;
    int pom1=v1.sati*3600+v1.minute*60+v1.sekunde;
    int pom2=v2.sati*3600+v2.minute*60+v2.sekunde;
    int pom=pom1+pom2;
    povratno.sati=pom/3600;
    pom=pom%3600;
    povratno.minute=pom/60;
    pom=pom%60;
    povratno.sekunde=pom;
    if(povratno.sati>23) povratno.sati=povratno.sati%24;
   
    
    return povratno;
    
}

int main ()
{
    Vrijeme v1,v2;
    
    try{
        std::cout<<"Unesite prvo vrijeme (h m s): ";
        std::cin>>v1.sati>>v1.minute>>v1.sekunde;
        TestirajVrijeme(v1);
        std::cout<<"Unesite drugo vrijeme (h m s): ";
        std::cin>>v2.sati>>v2.minute>>v2.sekunde;
        TestirajVrijeme(v2);
        std::cout<<"Prvo vrijeme: ";
        IspisiVrijeme(v1);
        std::cout<<"\nDrugo vrijeme: ";
        IspisiVrijeme(v2);
        std::cout<<"\nZbir vremena: ";
        IspisiVrijeme(SaberiVrijeme(v1,v2));
        
        
        
        
    }catch(std::domain_error er){
        std::cout<<er.what()<<std::endl;
    }
    
    
    
    
	return 0;
}