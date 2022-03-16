#include <iostream>
#include <string>

using namespace std;

string karakterek ="\";:'[]*&^%$#@!-*";
 
struct Person
{
    Person(){}
    Person(string f, string l, int a) : first{f}, last{l}, age{a}{
        if (age < 0 || age>150){
            throw runtime_error("Invalid age");
        }

        string name = first + last;

        for (char c : karakterek)
        {
            for (char c1 : name)
            {
                if (c == c1)
                {
                    throw runtime_error("Invalid name");
                }
            }
        }
            
    }
    

    private:
        string first;
        string last;
        int age;

    public:
        void set_first(string fr){
            first = fr;
        }
        string get_first(){
            return first;
        }
        void set_last(string lt){
            last = lt;
        }
        string get_last(){
            return last;
        }

        void set_age(int ag){
            age = ag;
        }
        int get_age(){
            return age;
        }
};

istream& operator >> (istream& is, Person p){
    string first;
    string last;
    int age;

    is >> first >> last >> age;
    p.set_first(first);
    p.set_last(last);
    p.set_age(age);

    p = Person(first,last,age);

    return is;
}

ostream& operator << (ostream& os, Person p){
    return os << p.get_first() << " " << p.get_last() <<  " " <<  p.get_age();
}

int main(){
    Person p;
    //p.name="Goofy";
    //p.age=63;
    p = Person("Goofy","Junior",63);

    cout << p.get_first() << " " << p.get_last() << " " << p.get_age() << endl;

    Person p2;
    Person p3;

    cin >> p2 >> p3;
    //cout << p2 << " " << p3 << endl;

    return 0;
}