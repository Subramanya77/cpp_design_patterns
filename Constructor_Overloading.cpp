/*
Constructor Overloading:
Two or more constructor having same number of arguments as other
*/

#include <string>
using namespace std;

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

    Customer(string nameArg,                //Customer() = constructor. 2nd customer obj with phone number
    string addrArg,
    string panArg,
    string aadharArg,
    string phonenumb
    ) :name{nameArg}, addr{addrArg}, pan{panArg}, aadhar{aadharArg}, phonenumb{phonenumbArg} {         
        this->name=nameArg;         // Avoid this assignment. Use as above ()universal init
    }

     Customer(string nameArg,                //Customer() = constructor. 2nd customer obj with phone number
    string addrArg,
    string panArg,
    string aadharArg,
    string phonenumb,
    string emailid
    ) :name{nameArg}, addr{addrArg}, pan{panArg}, aadhar{aadharArg}, phonenumb{phonenumbArg}, emailid{emailidArg} {         
        this->name=nameArg;         // Avoid this assignment. Use as above ()universal init
    }
}


int main(){
    //Customer obj(); //VEXPARSING issue, treats obj() as funtion
    Customer customerObj1 {"tom", "blr","ads45sd","1233456"};
    Customer customerObj1 {"tom", "blr","ads45sd","1233456","99383938293"};     //constructor with same number of argument
    Customer customerObj1 {"tom", "blr","ads45sd","1233456","asdsj@.com"};       //constructor with same number of argument
    return 0;
}

/*
Solution for Constructor Overloading:
Telescopic Constructor Chain
*/
