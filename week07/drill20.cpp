#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

template<typename T>
void print(const T& t){

    for (auto a : t)
    {
        cout << a << " ";
    }
    cout << endl;

    //for_each(t.begin(), t.end(), [](int e){cout << e << " ";});
}

template<typename C>
void inc(C& c, int n){
    for(auto& i : c){
        i+=n;
    }
}

template<typename iter1, typename iter2>
iter2 orai_copy(iter1 f1, iter1 e1, iter2 f2){
    for (iter1 p =f1; p!=e1; ++p){
        *f2++=*p;
    }
    return f2;
}

int main(){

    /*int t[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int t2[10];
    copy(begin(t),end(t),begin(t2));
    vector<int> vi2 = vi;
    list<int> li2 = li;

    for (int i = 0; i < 10; i++)
    {
        cout << t2[i] << " ";
    }*/


    constexpr int size = 10;

    int arr[size];
    for (int i = 0; i < size; ++i) arr[i] = i;

    array<int,size> ai;
    copy(arr,arr+size,ai.begin());

    vector<int> vi(size);
    copy(arr,arr+size,vi.begin());

    list<int> li(size);
    copy(arr,arr+size,li.begin());
    
    array<int,size> ai2 = ai;
    vector<int> vi2 = vi;
    list<int> li2 = li;

    print(ai);
    print(vi);
    print(li);


    inc(ai,2);
    inc(vi,3);
    inc(li,5);

    print(ai);
    print(vi);
    print(li);

    orai_copy(ai2.begin(),ai2.end(),vi2.begin());
    orai_copy(li2.begin(),li2.end(),ai2.begin());

    print(ai2);
    print(vi2);
    print(li2);

    vector<int>::iterator vit;
    vit = find(vi2.begin(), vi2.end(),3);

    if(vit != vi2.end()){
        cout << "Found at: " << distance(vi2.begin(), vit) << endl;
    }else{
        cout << "Not found" << endl;
    }

    return 0;
}