#include <iostream>
#include <memory> // Include the memory header for std::unique_ptr
using namespace std;

class ErrorInfo {
    public:
        string methodName;
        string lineNumber;
        string message;
};

int div_fun(int numerator, int divisor) {
    int result;
    cout << "div_fun begins" << endl;
    if (divisor <= 0){
        ErrorInfo errorDetails;
        errorDetails.methodName = "div_fun";
        errorDetails.lineNumber = "13";
        errorDetails.message = "Divisor cannot be 0 or less than 0";
        throw errorDetails;                                             //when ever throw is executed, control will skip all the lines below that and returns to main
    }
    result = numerator / divisor;

    cout << "div_fun ends" << endl;
    return result;
}

void init() {
    cout << "init begins" << endl;
    try{
        int result = div_fun(10,0);
        cout << "init ends : "<< result << endl;
    }
    catch(ErrorInfo& exObj) {
        cout << "Method name : "<< exObj.methodName << endl;
        cout << "Line name : "<< exObj.lineNumber << endl;
        cout << "Message : "<< exObj.message << endl;
    }
    
}

int main() {
    cout << "main begins" << endl;
    init();
    cout << "main ends" << endl;
}

/*
Output:
main begins
init begins
div_fun begins
Method name : div_fun
Line name : 13
Message : Divisor cannot be 0 or less than 0
main ends
*/
