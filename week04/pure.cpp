#include <iostream>
#include <cmath>

int absolute(int val){
    return abs(val);
}

int main(){
    std::cout << "Absolute value of 0.025: " << abs(0.025) << std::endl;
    std::cout << "Absolute value of 25: " << abs(25) << std::endl;
}