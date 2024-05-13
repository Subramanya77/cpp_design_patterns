/*
Exception -> Information about run time error.
- Threads will get exception, handle the exception.
- Catch blocks will handle exceptions. So prevent exceptions.
- Try block will educate the thread about exception.
*/

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
    int result = div_fun(10,0);
    cout << "init ends : "<< result << endl;
}
int main(){
    cout << "main begins" << endl;
    init();
    cout << "main ends" << endl;
}

/*
OUTPUT:
main begins
init begins
div_fun begins
Code Exited .Floating point exception !
*/
