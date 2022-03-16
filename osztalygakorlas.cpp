#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

struct Lany{
    Lany(){}           //Üres konstruktor
    Lany(string n,int k, bool sngl, bool crs) : nev{n}, kor{k}, szinglie{sngl}, crushe{crs}{}     //Ha nem írok a kapcsos zárójel közé, akkor nem kötöm feltételhez az 

    private:
        bool crushe;

    protected:
        bool szinglie;

    public:
        string nev;
        int kor;

        void set_szinglie(bool igennem){
            szinglie = igennem;
        }
        bool get_szinglie(){
            return szinglie;
        }

        void set_crushe(bool igennem){
            crushe = igennem;
        }
        bool get_crushe(){
            return crushe;
        }

    void SetalniMegy(){
        if (szinglie == false){
            cout << "Elmegyek veled sétálni te csöves\n";
        }else{
            cout << "Van barátom, de ígyis jövök mert mercid van:)\n";
        }
    }
};

struct Crush:Lany{
    int gyerekekszama = rand() % 7 + 1;

    void SetalniMegy(){
        if (szinglie == false){
            cout << "habáár BIZTOS hogy NEM megyek el veled sétálni, meg amúgyis vigyázni kell a " << gyerekekszama << " gyerekemre \n";
        }else{
            cout << "habáár BIZTOS hogy NEM megyek el veled sétálni, amúgyis ma átjön az exem \n";
        }
    }
};



ostream& operator << (ostream& os, Lany l)
{
    return os << l.nev << " " << l.kor << " " << l.get_szinglie() << endl;;
}

istream& operator >> (istream& is, Lany l){
     string nev;
     int kor;
     bool single;
     bool crushe;

     is >> nev >> kor >> single >> crushe;
     l.set_szinglie(single);
     l.set_crushe(crushe);

    //nem tudom meghívni a c.SetalniMegy methodot

     l.SetalniMegy();
     
     l=Lany(nev,kor,single,crushe);
     
     return is;
} 

int main(){

    srand(time(NULL));

    Lany l;
    Crush c;

    l = Lany("Daniella",19,1,1);

    cout << l.nev << " " << l.kor << " " << l.get_szinglie() << " " << l.get_szinglie() << endl;
    l.SetalniMegy();
    c.SetalniMegy();

    Lany l2;
    Lany l3;

    cin >> l2 >> l3;

    return 0;
}