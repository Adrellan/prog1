#include <iostream>
#include <string>
#include <vector>

using namespace std;

string karakterek ="\";:'[]*&^%$#@!-*";
 
struct Person
{
    public: 
        Person(){};
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
        };
		
		string first_f() const { return first; }
		string last_l() const { return last; }
		int age_a() const { return age; }

	private:
		string first;
		string last;
		int age;	
    
        /*void set_first(string fr){
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
        }*/
};

istream& operator >> (istream& is, Person& p){
    string first;
    string last;
    int age;

    is >> first >> last >> age;
    //p.set_first(first);
    //p.set_last(last);
    //p.set_age(age);

    p = Person(first,last,age);

    return is;
}

ostream& operator << (ostream& os, Person& p){
    return os << p.first_f() << " " << p.last_l() <<  " " <<  p.age_a();
}

int main(){
    //Person p;
    //p.name="Goofy";
    //p.age=63;
    Person p("Goofy","Junior",63);

    cout << p.first_f() << " " << p.last_l() << " " << p.age_a() << endl;

    Person p2;

    cin >> p2;
    cout << p2 << endl;

    vector<Person> vector;
	for(Person p; cin>>p;){
		if(p.first_f() == "end") break;
		vector.push_back(p);
	}
	for(Person p:vector){
		cout << p;
    }
    return 0;
}