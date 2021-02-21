//TP 2016/2017: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
int main ()
{
    double a, b, c, min_ugao;
    cout << "Unesite tri broja: ";
    cin >> a >> b >> c;
    if(a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a){
        double obim=a+b+c;
        double povrsina=std::sqrt((obim/2)*(obim/2-a)*(obim/2-b)*(obim/2-c));
        double ugao1=std::acos((a*a+b*b-c*c)/(2*a*b));
        double ugao2=std::acos((c*c+b*b-a*a)/(2*c*b));
        double ugao3=std::acos((a*a+c*c-b*b)/(2*a*c));
        if(ugao1<ugao2 && ugao1<ugao3) min_ugao=ugao1;
        else if (ugao2<ugao1 && ugao2<ugao3) min_ugao=ugao2;
        else min_ugao=ugao3;
        double stepeni1=(min_ugao*180)/(4*atan(1));
        int stepeni=int(stepeni1);
        double minute1=(stepeni1-stepeni)*60;
        int minute=int(minute1);
        int sekunde=(minute1-minute)*60;
        
        cout << "Obim trougla sa duzinama stranica " << a << ", " << b <<
        " i " << c << " iznosi " << obim << "." << endl;
        cout << "Njegova povrsina iznosi " << povrsina << "." << endl;
        cout << "Njegov najmanji ugao ima " << stepeni << " stepeni, " << minute
        << " minuta " << "i " << sekunde << " sekundi.";
        
    }
    else cout << "Ne postoji trougao cije su duzine stranica " << a << ", " 
    << b << " i " << c << "!" << endl;
    
	return 0;
}