// auto_ptr (smartpointer)
// In modern c++, 3 smart pointers are there. 
/*
1. unique(auto), unique_ptr
2. shared
3. weak

whenever we need to create a obj for smart pointers, there is a factory(make_unique) 
which provides the obj and always keeps it in stack
*/


// 10/2

#include <iostream>
#include <memory> // Include the memory header for std::unique_ptr
using namespace std;

int div_fun(int numerator, int divisor) {
    cout << "div_fun begins" << endl;
    int result = numerator/divisor;
    cout << "div_fun ends" << endl;
    return result;
}

void init(){
    cout << "init begins" << endl;
    int result = div_fun(10,2);
    cout << "init ends : "<< result << endl;
}
int main(){
    cout << "main begins" << endl;
    init();
    cout << "main ends" << endl;
}

/* OUTPUT:
main begins
init begins
div_fun begins
div_fun ends
init ends : 5
main ends
*/
