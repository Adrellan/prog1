#include <iostream>

using namespace std;

template<class T>
class A{
    public:
    T pont;
    virtual T abs(T n) = 0;  
};

template<class T>
class  B2: public A<T>{
    public:
    T abs(T n){ return n*-1; };
};

int main (){
    B2<int> b;
    cout << b.abs(15);

    return 0;
}