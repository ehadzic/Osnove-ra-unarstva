/* TP 2016/2017: Tutorijal 3, Zadatak 6

   Autotestove pisao Haris Hasic. Sva pitanja
   sugestije i prijave gresaka mozete slati na
   mail: hhasic2@etf.unsa.ba
   
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
typedef std::vector<std::vector<int>>Matrica;
typedef std::vector<int>vektor;
int NajvecaSirina(Matrica a){
   int max=0;
   for(int i=0;i<a.size();i++){
      for(int j=0;j<a[i].size();j++){
         int suma=0;
         int n=a[i][j];
         if(n<0){
            suma++;
         }
         while(n!=0){
            suma++;
            n/=10;
         }
         if(suma>max) max=suma;
      }
   }
   return max;
}

Matrica KroneckerovProizvod(vektor a, vektor b){
   int n=a.size();
   int m=b.size();
   Matrica c(n,vektor(m));
   for(int i=0; i<a.size();i++){
      for(int j=0; j<b.size();j++)
         c[i][j]=a[i]*b[j];
      
   }
   return c;
}

int main ()
{
   int a1,b1;
   vektor a,b;
   cout<<"Unesite broj elemenata prvog vektora: ";
   cin>>a1;
   cout<<"Unesite elemente prvog vektora: ";
   for(int i=0; i<a1; i++){
      cin>>b1;
      a.push_back(b1);
   }
    cout<<"Unesite broj elemenata drugog vektora: ";
    cin>>b1;
    cout<<"Unesite elemente drugog vektora: ";
    for(int i=0; i<b1; i++){
      cin>>a1;
      b.push_back(a1);
   }
   cout<<std::endl;
   Matrica c=KroneckerovProizvod(a,b);
   int x=NajvecaSirina(c);
   x++;
   for(int i=0; i<c.size();i++){
      for(int j=0;j<c[i].size();j++)
      cout<<std::setw(x)<<c[i][j];
      cout<<std::endl;
   }
	return 0;
}