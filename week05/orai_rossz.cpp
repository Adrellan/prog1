#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

struct Person{  

    vector<char> characters = {'[',']',',',';','&','^','%','#','$','@','!','\''};

    Person(){}
    //Person(string n, int age) : n{n}, a{a} {
    Person(string f,string l, int age) : f{f}, l{l}, a{a} {
        if(age<0 || age>=150){
            throw runtime_error("Invalid age");
        }

        string n = f+l;

        for(char& c : n) {
            for (int i = 0; i < characters.size(); i++)
            {
                if(c==characters[i]){
                    throw runtime_error("Invalid name");
                }
            }
            
        }
    };

    //string name() const{ return n; }            //Ezek azért kellenek, mert private lett a két változónk
    string first() const{ return f; } 
    string last() const{ return l; }   
    int age() const{ return a; }

    private:
        //string n;
        string f;
        string l;
        int a;
};

ostream& operator << (ostream& os, const Person& p){
    return os << p.first() << " " << p.last() << " " << p.age();            
}

istream& operator >> (istream& is, Person& p){
    //string n;
    string f;
    string l;
    int a;

    //is >> n >> a;
    is >> f >> l >> a;
    //p = Person(n,a);
    p=Person(f,l,a);

    return is;
}

int main(){
    Person p;
    //p.name="Goofy";                                     //Itt már nem tudunk adatot rögzíteni
    //p.age=62;

    p = Person("Goofy","as",63);

    cout << p.first() << " " << p.last() << " " << p.age() << endl;

    Person p2;
    Person p3;

    cin >> p2 >> p3;
    cout << p2 << " " << p3 << endl;

    vector <Person> vec;

    for (Person p; cin >> p;){  //while(cin>>p)
        if(p.first() == "end") break;
        vec.push_back(p);
    }

    for (Person p: vec){
        cout << p << endl;
    }
    


    return 0;
}