//A kulcs az akkor jó, ha egyediséget szeretnénk használni
//A set-be nem lehet duplikáció

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <map>

using namespace std;

template<typename K, typename V>
void print(map<K,V>& m){
    /*for(pair<K,V> p : m){
        cout << p.first() << " " << p.second() << endl;
    }*/

    for(auto& p : m){
        cout << p.first << "\t" << p.second << endl;
    }
}

void read_map(map<string, int>& m){
    string s;
    int i;
    while(m.size()<5){
        cin >> s >> i;
        m[s] = i;
        //m.insert(make_pair(s,i));                                //az insert NEM írja felül a megadott értéket
    }
}

void msi_to_mis(map<string, int>& m1, map<int,string>& m2){
    for(auto&a : m1){
        m2.insert(make_pair(a.second,a.first));
    }
}

int main(){

    try{
        map<string, int> msi;
        msi["a"]=2;
        msi["b"]=5;
        msi["c"]=14;
        msi["d"]=16;
        msi["e"]=7;
        msi["f"]=11;
        msi["qwerty"]=8;
        msi["asd"]=6;
        msi["dda"]=3;
        msi["adwd"]=1;

        print(msi);

        msi.erase("a");                     // 'a' elem törlése
        cout << endl;
        print(msi);

        msi.erase(msi.begin(),msi.end());  // msi törlése elejétől a végéig
        cout << endl;
        print(msi);

        cout << "Adj meg 10 kulcs-érték párt: \n";
        read_map(msi);
        print(msi);

        int sum=0;
        for (auto& a: msi)
        {
            sum+=a.second;
        }
        cout << "A számok összege: " << sum << endl; 

        map<int, string> mis;
        msi_to_mis(msi,mis);
        print(mis);

    }catch(exception& e){
        cerr << "Exception: " << e.what() << '\n';
        return 1;
    }catch(...){
        cerr << "Unknown exception" << '\n';
        return 2;
    }
    return 0;
}