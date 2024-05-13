//TEMPLATES / Parametric polymorphism
//Parametric polymorphism

#include <iostream>
#include <string>
using namespace std;
int add (int operand1, int operand2)        //operand 1,2 and its return is same type 'int'. So like parameters, its datatypes can also have a placeholders.
                                            // since here all 3 have same data types, it needs single placeholder.
{
    return operand1 + operand2;

}

int main() {
    int operand1 = 10;
    int operand2 = 20;
    int result = operand1 + operand2;
}
//--------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
template<typename T>           'T' can be any name
T add(T operand1, T operand2)
//int add (int operand1, int operand2)
{
    return operand1 + operand2;

}

int main() {
    //int operand1 = 10;
    //int operand2 = 20;
    int result = add<int>(100,200);         //Template Instantiation. Every time template is instantiated, a separate function is added. So more space.
                                            //c++ uses compile time instantiation not run time instantiation.
    cout << result;
}

//----------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

template<typename T>
T add(T operand1, T operand2)
//int add (int operand1, int operand2)
{
    return operand1 + operand2;

}

int main() {
    //int operand1 = 10;
    //int operand2 = 20;
    int result = add<int>(100,200);
    cout << result <<endl;
    string strresult = add<string>("hello","world");
    cout << strresult << endl;
}
//output
/*
300
helloworld
*/
