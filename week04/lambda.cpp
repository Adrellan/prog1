#include <iostream>

    /*
    [] lambda introducer
    () argument list
    {} function body

    [] captures nothing
    [&] captures all by reference
    [=] captures all by value
    [&A, =B] A by reference, B by value
    [=, &A] A by reference
    */

int main(){
    [](){
        std::cout << "Hello C++ lambda" << std::endl;
    }

    ();

    auto sum = [](double A, double B) {return A+B;};

    auto add = sum;

    std::cout << add(3.25,5.65) << std::endl;

    auto add2 = [](double A, double B) -> double {return A+B;}; //csak megadtam h double lesz a visszatérési érték
    std::cout << add2(3.25,5.65) << std::endl;

    double pi = 3.1416;

    std::cout << "The value of pi is " << pi << std::endl;

    auto funct = [&pi](double inc){                                        //konkrétan a pi programállapotot fogja felhasználni, nem lehet változtatni a pi értékét (kivéve ha & kerül elé)
        std::cout << "The value of pi is " << pi+inc << std::endl;
        pi+=inc;
    };

    funct(2);

    auto gene_lambda = [](auto arg) {return arg;};

    std::cout << gene_lambda(5) << std::endl;
    std::cout << gene_lambda(3.1416) << std::endl;

}