#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S {
    S (T vv = 0) : val{vv}{}                //vv-vel tolti fel a val-t
    T& get();
    const T& get() const;                   //valahol lesz egy get() függvény, amit máshol definiálunk
    void set(T new_t) { val = new_t; };
    void operator=(const T& s);
    private:
        T val;
};

//const and non-const get()

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
    return val;
}

template<typename T>
void S<T>::operator=(const T& s){
    val = s;
}

template<typename T>
void read_val(T& v){
    cin >> v;
}

template<typename T>
ostream& operator<< (ostream& os, vector<T>& val ){
    os << "{";
    for (int i = 0; i < val.size(); ++i)
    {
        os << val[i] << (i < val.size()-1 ? ", " : " ");
    }
    os << "}\n";
    return os;
}

template<typename T>
istream& operator>> (istream& is, vector<T>& v){
    char ch = 0;
    is >> ch;
    if(ch != '{'){
        is.unget();
        return is;
    }
    for(T val; is >> val;){
        v.push_back(val);
        is >> ch;
        if (ch!=',') break;
    }
    return is;
}

int main(){
    S<int> s;
    S<int> si {37};
    S<char> sc {'c'};
    S<double> sd {3.2};
    S<string> ss {"Hello"};
    S<vector<int>> svi {vector<int>{1,1,2,3,4,8}}; //s tipusu objektum, vektort tartalmaz, ami int-eket tartalmaz


    cout << "S<int> : " << s.get() << endl;
    cout << "S<int> : " << si.get() << endl;
    cout << "S<char> : " << sc.get() << endl;
    cout << "S<double> : " << sd.get() << endl;
    cout << "S<string> : " << ss.get() << endl;
    //cout << svi.get();

    cout << "S<vector> : ";
    for(auto& a : svi.get()){
        cout << a << ' ';
    }
    cout << endl;

    sc.set('s');
    cout << "S<char> : " << sc.get() << endl;

    sd = 42.1;
    cout << "S<double> : " << sd.get() << endl;

    int ii;
    read_val(ii);
    S<int> si2 {ii};

    double dd;
    read_val(dd);
    S<double> sd2 {dd};

    string str;
	read_val(str);
	S<string> ss2 {str};

    cout << "S<int> : " << si2.get() << endl;
    cout << "S<double> : " << sd2.get() << endl;
    cout << "S<string> : " << ss2.get() << endl;

    vector<int> vi2;
    read_val(vi2);
    S<vector<int>> svi2 {vi2};

    cout << "S<vector<int>> svi2: " << svi2.get() << endl;

    return 0;
}