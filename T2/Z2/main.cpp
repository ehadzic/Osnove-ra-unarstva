//TP 2016/2017: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

bool TestPerioda(std::vector<double>v,int p){
    if(p>=int(v.size()) || p<=0 ) return false;
    for(int i =0; i<int(v.size()-p); i++){
        if(v.at(i)!=v.at(i+p)) return false;
    }
    return true;
}

int OdrediOsnovniPeriod(std::vector<double>v){
    for(int i=1; i<int(v.size()); i++){
        if(TestPerioda(v,i)==true) return i;
    }
    return 0;
}

int main ()
{   
    double a;
    std::vector<double>v;
    std::cout<<"Unesite slijed brojeva (0 za kraj): ";
    do{
        std::cin>>a;
        if(a==0) break;
        v.push_back(a);
    }while(a!=0);
    int b=OdrediOsnovniPeriod(v);
    if(b==0)
    std::cout<<"Slijed nije periodican!";
    else std:: cout<<"Slijed je periodican sa osnovnim periodom " << b << ".";
    
	return 0;
}