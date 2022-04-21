#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "./../GUI/Matrix.h"
#include "./../GUI/MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
{
    try
    {

        cout << "sizeof:\n";
        cout << "char\t" << sizeof(char) << '\n';
        cout << "sort\t" << sizeof(short) << '\n';
        cout << "int\t" << sizeof(int) << '\n';
        cout << "long\t" << sizeof(long) << '\n';
        cout << "float\t" << sizeof(float) << '\n';
        cout << "double\t" << sizeof(double) << '\n';
        cout << "int\t" << sizeof(int *) << '\n';
        cout << "double\t" << sizeof(double *) << '\n';

        // 1 dimenziós mátrixok
        cout << "\nMatrix sizes:\n";
        Matrix<int> a(10);
        Matrix<int> b(10);
        Matrix<double> c(10);

        // 2
        Matrix<int, 2> d(10, 10);

        // 3
        Matrix<int, 3> e(10, 10, 10);

        cout << "1D int, 10 elem:\t\t" << sizeof(a) << '\n';
        cout << "1D int, 100 elem:\t\t" << sizeof(b) << '\n';
        cout << "1D double, 10 elem:\t\t" << sizeof(c) << '\n';
        cout << "2D int, 10x10 elem:\t\t" << sizeof(d) << '\n';
        cout << "3D int, 10x10x10 elem:\t\t" << sizeof(e) << '\n';

        // Az index csak egy long típus a headerben

        cout << "\nNumber of elements:\n";

        cout << "a:\t" << a.size() << '\n';
        cout << "b:\t" << b.size() << '\n';
        cout << "c:\t" << c.size() << '\n';
        cout << "d:\t" << d.size() << '\n';
        cout << "e:\t" << e.size() << '\n';

        /*int i;
        cout << "\nEnter ints:";
        while(cin >> i){
            errno=0;
            double d = sqrt(i);
            if(errno==EDOM){
                cout << "no square root\n";
            }else{
                cout << "sqrt(" << i << ") = " << d << '\n';
            }
        }

        cin.clear();
        cin.ignore();
        */

        int number;
        cout << "Write a number: " << endl;
        cin >> number;
        if (number >= 0)
        {
            cout << sqrt(number) << '\n';
        }
        else
        {
            cout << "no square root\n";
        }

        /*cout << "Enter ten floats " << endl;
        Matrix<double> m2(10);
        for (int i = 0; i < m2.size(); ++i)
        {
            double num;
            cin >> num;
            if (!cin)
                throw runtime_error("Problem reading from cin");
            c[i] = num;
        }

        cout << c;*/

        int n, m;
        cout << "\nEnter n:\n";
        cin >> n;
        cout << "Enter m:\n";
        cin >> m;
        Matrix<int, 2> m3(n, m);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                m3(i - 1, j - 1) = i * j;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << m3(i, j) << "\t";
            }
            cout << endl;
        }

        Matrix<complex<double>> mcomp(10);

        cout << "\nEnter 10 complex number (Re Im):\n";
        complex<double> comp;
        for (int i = 0; i < 10; ++i)
        {
            cin >> comp;
            if (!cin)
                throw runtime_error("Problem reading complex number");
            mcomp[i] = comp;
        }

        complex<double> sum;
        for (Index i = 0; i < mcomp.size(); ++i)
        {
            sum += mcomp[i];
        }
        cout << "sum: " << sum << '\n';

        Matrix<int, 2> mx(2, 3);

        cout << "Please, enter 6 number" << endl;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> mx(i, j);
            }
        }
        cout << endl;
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << mx(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << '\n';
    }
    catch (...)
    {
        cerr << "Exception!";
    }
}