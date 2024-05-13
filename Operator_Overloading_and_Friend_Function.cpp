#include <iostream>
#include <string>
using namespace std;

class BankAcc {
    private:
        int balance;
    public:
        //BankAcc() : balance{0} {} // Default constructor
        BankAcc (int initBalance) : balance{initBalance} {}
        int getBalance() const {
            return this->balance;
        }
        //const BankAcc* const this
        BankAcc operator+(const BankAcc & operandTwo) const {                   //operator overloading
            BankAcc newAcc{0};                                                  //alternate to line 86
            newAcc.balance = this->getBalance() + operandTwo.getBalance();
            return newAcc;
        }
    friend ostream& operator<<(ostream& out, const BankAcc& operandTwo) {           
        out << "Current Balance is " << operandTwo.balance;     
        return out;
    }
};

int main () {
    BankAcc acc1{1000};
    BankAcc acc2{2000};
    cout << acc1 << endl;
    cout << acc2 << endl;

    BankAcc acc3 = acc1 + acc2;
    cout << "The balance of new acc is: "<< acc3.getBalance() << endl; // Corrected typo here
}

/*
output:
Current Balance is 1000
Current Balance is 2000
The balance of new acc is: 3000
*/
