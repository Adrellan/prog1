#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

struct Item{
	string name;
	int iid;
	double value; 
	Item(string n, int i, double v): name{n}, iid{i}, value{v} {}
};
struct comp_name{
	bool operator()(const Item& a, const Item& b){
		return a.name < b.name;
	}
};
struct comp_iid{
	bool operator()(const Item & a, const Item & b){
		return a.iid < b.iid;
	}
};
struct comp_value{
	bool operator()(const Item & a, const Item & b){
		return a.value > b.value;
	}
};
void print(const vector<Item> v){
	for(const Item& a : v){
		cout  << a.name << " " << a.iid << " " << a.value << endl;
	}
	cout << endl;
}

void print_list(const list<Item> v){
	for(const Item& a : v){
		cout  << a.name << " " << a.iid << " " << a.value << endl;
	}
	cout << endl;
}
struct find_name{
	string name;
	find_name(string& n): name{n}{};
	bool operator()(const Item& a){
		return a.name == name;
	}
};

struct find_iid{
	int id;
	find_iid(int& n): id{n}{};
	bool operator()(const Item& a){
		return a.iid == id;
	}
};

int main(){
try{

	cout << "Vector:" << endl; 
	const string input = "input1.txt";
	ifstream ifs{input};
	if(!ifs) throw runtime_error("Could not read from file: " + input);
	
	vector<Item> vi;
	for(int i = 0; i < 10; ++i){
		string n;
		int id;
		double v;
		ifs >> n >> id >> v;
		vi.push_back({n,id,v});
	}

	print(vi);
	cout << "Order by name:" << endl; 
	sort(vi.begin(), vi.end(), comp_name());
	print(vi);

	cout << "Order by id:" << endl; 
	sort(vi.begin(), vi.end(), comp_iid());
	print(vi);

	cout << "Order by value:" << endl; 
	sort(vi.begin(), vi.end(), comp_value());
	print(vi);


	vi.push_back({"horse shoe", 99, 12.34});
	vi.push_back({"Canon S400", 9988, 499.95});
	print(vi);
	
	for(int i = 0; i < vi.size(); i++){
		if(vi[i].name == "geekbar") vi.erase(vi.begin() + i);
		if(vi[i].name == "horse shoe") vi.erase(vi.begin() + i);
	}
	print(vi);

	for(int i = 0; i < vi.size(); i++){
		if(vi[i].iid == 1) vi.erase(vi.begin() + i);
		if(vi[i].iid == 5) vi.erase(vi.begin() + i);
	}
	print(vi);

	cout << "List:" << endl; 

	const string input2 = "input2.txt";
	ifstream ifs2{input2};
	if(!ifs2) throw runtime_error("Could not read from file: " + input2);

	list<Item> li;
	for(int i = 0; i < 10; ++i){
		string n;
		int id;
		double v;
		ifs2 >> n >> id >> v;
		li.push_back({n,id,v});
	}
	print_list(li);

	cout << "Order by name:" << endl; 
	li.sort(comp_name());
	print_list(li);

	cout << "Order by id:" << endl; 
	li.sort(comp_iid());
	print_list(li);

	cout << "Order by value:" << endl; 
	li.sort(comp_value());
	print_list(li);

	li.push_back({"horse shoe", 99, 12.34});
	li.push_back({"Canon S400", 9988, 499.95});
	print_list(li);

	string name1 = "kenyér";
	string name2 = "monster";
	list<Item>::iterator lit = find_if(li.begin(), li.end(), find_name(name1));
	li.erase(lit);

	lit = find_if(li.begin(), li.end(), find_name(name2));
	li.erase(lit);

	print_list(li);

	int num1 = 3;
	int num2 = 7;
	lit = find_if(li.begin(), li.end(), find_iid(num1));
	li.erase(lit);
	lit = find_if(li.begin(), li.end(), find_iid(num2));
	li.erase(lit);
	print_list(li);



}catch(exception& e){
	cerr << "Exception: " << e.what() << endl;
	return 1;
}catch(...){
	cerr << "Unknow exception " << endl;
		return 2;
}


}