/* TP 2016/2017 (Tutorijal 4, Zadatak 3)

   Autotestovi by Eldar Kurtic, sva pitanja, sugestije i prijave gresaka javite na 
   mail ekurtic3@etf.unsa.ba
   
   NAPOMENA: testovi ce biti konacni TEK pred pocetak tutorijala. Zbog toga pokrenite
   testove za SVE zadatke na tutorijalu, da se ne bi desila situacija da neko uradi
   zadatak ranije i prolazi mu npr. 5/5 testova a naknadno dodano jos 2 testa koja mu
   padaju!
   
*/ 

#include <iostream>
#include <vector>
#include <string>

int dupli(std::vector<std::string>v, std::string s){
   int count(0);
   
   for(unsigned int i=0; i<v.size();i++){
      if(v.at(i)==s) count++;
   }
   return count;
}

void ZadrziDuplikate(std::vector<std::string>&v){
   std::string tmp;
   std::vector<std::string>vManip;
   
   for(unsigned int i=0; i<v.size(); i++){
      if(dupli(v,v.at(i))>1 && !dupli(vManip,v.at(i))) vManip.push_back(v.at(i));
   }
   v=vManip;
   
}

int relate(std::string s1, std::string s2){
   char x,y;
   for(unsigned long int i=0; i<s1.length();i++){
      if(!(i<s2.length())) return -1;
      x=s1.at(i);
      y=s2.at(i);
      
      if(x<='Z' && x>='A') x+='a'-'A';
      if(y<='Z' && y>='A') y+='a'-'A';
      if(x!=y) return x-y;
   }
   return 0;
}

void IzdvojiKrajnjeRijeci(std::vector<std::string>v, std::string &s1, std::string&s2){
   if(v.size()==0){
      s1="";
      s2="";
      return;
   }
   std::string tmp, max(v.at(0)),min(v.at(0));
   
   for(int i=0; i<int(v.size()); i++){
      if(relate(v.at(i),max)>0) max=v.at(i);
      if(relate(v.at(i),min)<0) min=v.at(i);
   }
   s1=min;
   s2=max;
   
}
int main(){
   std::cout<<"Koliko zelite rijeci unijeti: ";
   int n;
   std::cin>>n;
   std::vector<std::string>v(n);
   for(int i =0; i<n; i++){
      std::cin>>v.at(i);
   }
   std::string sMin, sMax;
   IzdvojiKrajnjeRijeci(v,sMin, sMax);
   std::cout<<"Prva rijec po abecednom poretku je: "<< sMin << std::endl;
   std::cout<<"Posljednja rijec po abecednom poretku je: "<< sMax << std::endl;
   std::cout<<"Rijeci koje se ponavljaju su: ";
   ZadrziDuplikate(v);
   for(unsigned int i=0; i<v.size();i++){
      std::cout<<v.at(i)<<" ";
   }
   return 0;
}