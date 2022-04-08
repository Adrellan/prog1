#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <iterator>

using namespace std;

class Less_than{
    double v;
    public: Less_than(double vv) : v{vv}{}
    bool operator()(const double val) { return val < v; }
};

template<typename C>
void print(const C& c, char sep = '\n'){
    cout << "Container elements: " << endl;

    for(const auto elem: c){
        cout << elem << sep;
    }

    cout << endl;
}

int main(){
    try{

        const string iname {"input_floats.txt"};
        ifstream ifs {iname};
        if(!ifs) throw runtime_error("Could not read the file: "+iname);

        vector<double> vd;
        for (double d; ifs >> d; )
        {
            vd.push_back(d);
        }
        print(vd);

        vector<int> vi(vd.size());
        
        /*for (auto& i : vd){
            vi.push_back(i);
        }*/
        
        copy(vd.begin(), vd.end(), vi.begin());
        print(vi);

        for(int i=0; i<vd.size(); i++){
            cout << vd[i] << '\t' << vi[i] << endl;
        }

        cout << endl;

        double sum_of_vd_elements= accumulate(vd.begin(), vd.end(), 0.0);
        cout << "Sum of the elements of vd: " << sum_of_vd_elements << endl;

        int sum_of_vi_elements= accumulate(vi.begin(), vi.end(), 0);
        cout << "Sum of the elements of vi: " << sum_of_vi_elements << endl;

        double diff = abs(sum_of_vd_elements-sum_of_vi_elements);
        cout << "Difference between two sum: " << diff << endl;

        reverse(vd.begin(),vd.end());   

        cout << endl;
        print(vd);
        
        double mean = sum_of_vd_elements / vd.size();
        cout << "Mean value of vd: " << mean << endl;

        vector<double> vd2;

        //copy_if(vd.begin(), vd.end(), vd2.begin(), [=](auto i){return i<mean;});
        
        //auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(mean));
        //vd2.resize(distance(vd2.begin(), it));

        for(int i=0; i<vd.size(); i++){
            if(vd[i]<mean)  vd2.push_back(vd[i]);
        }

        cout << endl;
        print(vd2);

        sort(vd.begin(), vd.end());

        print(vd);

    }catch(exception& e){
        cerr << e.what() << '\n';
        return 1;
    }catch(...){
        cerr << "Unknown exception\n";
        return 2;
    }
}