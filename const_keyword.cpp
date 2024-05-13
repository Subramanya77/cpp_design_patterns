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
        BankAcc operator+(const BankAcc & operandTwo) const {
            BankAcc newAcc{0};
            newAcc.balance = this->getBalance() + operandTwo.getBalance();
            return newAcc;
        }
};

int main () {
    BankAcc acc1{1000};
    BankAcc acc2{2000};
    cout << "The balance of acc 1 is: "<< acc1.getBalance() << endl;
    cout << "The balance of acc 2 is: "<< acc2.getBalance() << endl;

    BankAcc acc3 = acc1 + acc2;
    cout << "The balance of new acc is: "<< acc3.getBalance() << endl; // Corrected typo here
}

/*Output:
The balance of acc 1 is: 1000
The balance of acc 2 is: 2000
The balance of new acc is: 3000
*/
