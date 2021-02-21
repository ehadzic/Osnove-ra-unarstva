/*
    TP 16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
template <typename TipEl>
class Matrica
{
        int br_redova, br_kolona;
        TipEl **elementi;
        char ime_matrice;
        static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
        static void DealocirajMemoriju(TipEl **elementi, int br_redova);
        void KopirajElemente(TipEl **elementi);
public:
        Matrica(int br_redova, int br_kolona, char ime = 0);
        Matrica(const Matrica &m);
        Matrica(Matrica &&m);

        ~Matrica() {
                DealocirajMemoriju(elementi, br_redova);
        }
        Matrica &operator =(const Matrica &m);
        Matrica &operator =(Matrica &&m);

        friend std::istream &operator >> (std::istream &znak , Matrica &m) {
                for(int i=0; i<m.br_redova; i++) {
                        for(int j=0; j<m.br_kolona; j++) {
                                std::cout<<m.ime_matrice;
                                std::cout<<"("<<i+1<<","<<j+1<<") = ";
                                znak>>m.elementi[i][j];
                        }
                }
                return znak;
        }

        friend std::ostream &operator << (std::ostream &znak, const Matrica &m) {
                int sirina=znak.width();
                for(int i=0; i<m.br_redova; i++) {
                        for(int j=0; j<m.br_kolona; j++) {
                                znak<<std::setw(sirina)<<m.elementi[i][j];
                        }
                        znak<<std::endl;
                }
                return znak;
        }

        friend Matrica operator - (const Matrica &a, const Matrica &b) {
                if((a.br_redova!=b.br_redova) || (a.br_kolona!=b.br_kolona)) throw std::domain_error("Matrice nemaju jednake dimenzije!");
                Matrica c(a.br_redova,a.br_kolona);
                for(int i=0; i<a.br_redova; i++) {
                        for(int j=0 ; j<a.br_kolona; j++) {
                                c.elementi[i][j]=a.elementi[i][j]-b.elementi[i][j];
                        }
                }
                return c;
        }

        friend Matrica operator * (const Matrica &a, double n) {
                Matrica nova(a.br_redova,a.br_kolona);
                for(int i=0 ; i<a.br_redova; i++) {
                        for(int j=0 ; j<a.br_kolona; j++) {
                                nova.elementi[i][j]= a.elementi[i][j]*n;
                        }
                }
                return nova;
        }

        inline friend Matrica operator * (double n,const Matrica &a) {
                return a*n;
        }

        friend Matrica operator * (const Matrica &a , const Matrica &b) {
                if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
                Matrica c(a.br_redova,b.br_kolona);
                        for(int i=0; i<a.br_redova; i++) {
                                for(int j=0; j<b.br_kolona; j++) {
                                        int suma(0);
                                        for(int k=0; k<b.br_redova; k++) {
                                                suma+=a.elementi[i][k]*b.elementi[k][j];
                                        }
                                        c.elementi[i][j]=suma;
                                }
                        }

                return c;
        }

        friend Matrica operator + (const Matrica &a, const Matrica &b) {
                if((a.br_redova!=b.br_redova) || (a.br_kolona!=b.br_kolona)) throw std::domain_error("Matrice nemaju jednake dimenzije!");
                Matrica c(a.br_redova,a.br_kolona);
                for(int i=0; i<a.br_redova; i++) {
                        for(int j=0; j<a.br_kolona; j++) {
                                c.elementi[i][j]=a.elementi[i][j]+b.elementi[i][j];
                        }
                }
                return c;
        }

        friend Matrica &operator += (Matrica &a , const Matrica &b) {
                if((a.br_redova!=b.br_redova) || (a.br_kolona!=b.br_kolona)) throw std::domain_error("Matrice nemaju jednake dimenzije!");
                for(int i=0; i<a.br_redova; i++) {
                        for(int j=0; j<a.br_kolona; j++) {
                                a.elementi[i][j]+=b.elementi[i][j];
                        }
                }
                return a;
        }

        friend Matrica &operator -= (Matrica &a, const Matrica &b) {
                if((a.br_redova!=b.br_redova) || (a.br_kolona!=b.br_kolona)) throw std::domain_error("Matrice nemaju jednake dimenzije!");
                for(int i=0; i<a.br_redova; i++) {
                        for(int j=0; j<a.br_kolona; j++) {
                                a.elementi[i][j]-=b.elementi[i][j];
                        }
                }
                return a;
        }

        friend Matrica &operator *= (Matrica &a, const Matrica &b) {
                if(a.br_kolona!=b.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
                for(int i=0; i<a.br_redova; i++) {
                        for(int j=0; j<b.br_kolona; j++) {
                                int suma(0);
                                for(int k=0; k<b.br_redova; k++) {
                                        suma+=a.elementi[j][k]+b.elementi[k][j];
                                }
                                a.elementi[i][j]=suma;
                        }
                }
                return a;
        }

        friend Matrica &operator *= (Matrica &a, int n) {
                for(int i=0; i<a.br_redova; i++) {
                        for(int j=0; j<a.br_kolona; j++) {
                                a.elementi[i][j]=a.elementi[i][j]*n;
                        }
                }
                return a;
        }

        inline friend Matrica &operator *= (int n,Matrica &a) {
                return a*n;
        }

        void TestIndeksa(int indeks) {
                if(indeks<0) throw std::range_error("Neispravan indeks");
        }

        TipEl &operator () (int indeks, int drugi_indeks) {
                try {
                        TestIndeksa(indeks-1);
                        TestIndeksa(drugi_indeks-1);
                } catch(std::range_error greska) {
                        throw greska;
                }
                return elementi[indeks-1][drugi_indeks-1];
        }

        TipEl operator () (int indeks, int drugi_indeks) const {
                try {
                        TestIndeksa(indeks-1);
                        TestIndeksa(drugi_indeks-1);
                } catch(std::range_error greska) {
                        throw greska;
                }

                return elementi[indeks-1][drugi_indeks-1];
        }

        TipEl *operator [] (int indeks) {
                TestIndeksa(indeks);
                return elementi[indeks];
        }

        const TipEl *operator [] (int indeks) const {
                TestIndeksa(indeks);
                return elementi[indeks];
        }


};


template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
        TipEl **elementi(new TipEl*[br_redova] {});
        try {
                for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
        } catch(...) {
                DealocirajMemoriju(elementi, br_redova);
                throw;
        }
        return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
        for(int i = 0; i < br_redova; i++) delete[] elementi[i];
        delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
        br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
        elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
        for(int i = 0; i < br_redova; i++)
                for(int j = 0; j < br_kolona; j++)
                        Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
        br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
        elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
        KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
        br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
        m.br_redova = 0;
        m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
        if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
                TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
                DealocirajMemoriju(elementi, br_redova);
                elementi = novi_prostor;
        } else if(br_redova > m.br_redova)
                for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
        br_redova = m.br_redova;
        br_kolona = m.br_kolona;
        ime_matrice = m.ime_matrice;
        KopirajElemente(m.elementi);
        return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
        std::swap(br_redova, m.br_redova);
        std::swap(br_kolona, m.br_kolona);
        std::swap(ime_matrice, m.ime_matrice);
        std::swap(elementi, m.elementi);
        return *this;
}



int main()
{        
  int m,n;
  std::cout << "Unesi broj redova i kolona za matrice:\n";
  std::cin >> m >> n;
  try{
    Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    std::cout << "Unesi matricu A:\n";
    std::cin >> a;
    std::cout << "Unesi matricu B:\n";
    std::cin >> b;
    a = (a + b);
    std::cout<<a;
    Matrica<double> c= 3 * a;
  	std::cout<<c;
  	c=c-b;
   	std::cout<<c;
	std::cout << std::setw(4) << a;
  }
catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
  }
    catch(std::domain_error e) {
    std::cout << e.what();
  }
    catch(std::range_error e) {
    std::cout << e.what();
  }
}
