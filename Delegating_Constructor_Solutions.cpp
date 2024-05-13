// Solution for Delegation constuctor
#include <string>
using namespace std;                // god classes are anti-pattern. Can't change if requirements are changing.
class Customer{
    private:
    string name, addr, pan, aadhaar, mail, contact;
    public:
    Customer(string nameArg,                //Customer() = constructor. Our own constructor with mandate arguments
    string addrArg,
    string panArg,
    string aadharArg
    ) :name{nameArg}, addr{addrArg}, pan{panArg}, aadhar{aadharArg} {         //:name{} = universal initialization
        this->name=nameArg;         // Avoid this assignment. Use as above ()universal init
    }
   
    void setPhonenumb(string phoneNumArg){      //Instead of copying the same code, call the above Constructor itself
        this->phoneNumb = phoneNumbArg;
    }
    void setemailId(string emailIdArg){
        this->emailIdNumb = emailIdArg;
    }
};

class CustomerBuilder {                         //One more class is defined. To segregate the responsibility
    public:
    CustomerBuilder(string name, string address, string pan, string aadhar){

    }
}


int main(){
    //Customer obj(); //VEXPARSING issue, treats obj() as funtion
    Customer customerObj1 {"tom", "blr","ads45sd","1233456"};
    Customer customerObj1 {"tom", "blr","ads45sd","1233456","99383938293"};     //constructor with same number of argument
    Customer customerObj1 {"tom", "blr","ads45sd","1233456","asdsj@.com"};       //constructor with same number of argument
    return 0;
}
