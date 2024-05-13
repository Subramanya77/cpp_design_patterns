//MACRO
#include <iostream>
#include <string>
using namespace std;
#define ADD ((operand1)+(operand2))

template<typename T>
T add(T operand1, T operand2)
//int add (int operand1, int operand2)
{
    return operand1 + operand2;

}

int main() {
    int result = add<int>(100,200);
    cout << ADD(100, 200) << endl;
    cout << result <<endl;
    string strresult = add<string>("hello","world");
    cout << strresult << endl;
}
