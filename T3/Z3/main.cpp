/* TP 2016/2017: Tutorijal 3, Zadatak 3

   Autotestove pisao Haris Hasic. Sva pitanja
   sugestije i prijave gresaka mozete slati na
   mail: hhasic2@etf.unsa.ba
   
*/

#include <iostream>
#include <deque>
typedef std::deque<int> vektor;
using std::cout;
using std::cin;

bool Parnost (int n){
if(!n) return true;
int suma=0;
if(n<0) n=abs(n);
while(n!=0){
   suma+=n%10;
   n/=10;
}
if(suma%2==0)
   return true;
return false;
}

vektor IzdvojiElemente(vektor v, bool a){
   vektor b;
   for(int i:v){
      if(a==Parnost(i))
         b.push_back(i);
   }
   return b;
}

int main ()
{
   int n;
   cout<<"Koliko zelite unijeti elemenata: ";
   cin>>n;
   if(n<=0){
      cout<<"Broj elemenata mora biti veci od 0!";
      return 0;
   }
   cout<<"Unesite elemente: ";
   vektor a;
   int z;
   for(int i=0; i<n; i++){
      cin>>z;
      a.push_back(z);
   }
   vektor b,c;
   b=IzdvojiElemente(a,true);
   c=IzdvojiElemente(a,false);
   for(int x=0; x<b.size(); x++) {
      cout<<b[x];
      if(x<b.size()-1) cout << ",";
   }
   cout<<std::endl;
   for(int y=0; y<c.size(); y++) {
      cout<<c[y];
      if(y<c.size()-1) cout << ",";
   }
	return 0;
}