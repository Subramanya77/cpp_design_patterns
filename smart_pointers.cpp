/*Smart Pointers:
In modern c++, there are 3 smart pointers:
1. unique(auto), unique_ptr
2. shared
3. weak
whenever we need to create a obj for smart pointers, there is a factory(make_unique) 
which provides the obj and always keeps it in stack
*/

#include <iostream>
using namespace std;

class A{
        public:
            A(){
                cout << "A instantiated" << endl;
            }
            ~A(){
                cout << "A destructed" << endl;
            }

};
void instantiate (){
    A *ptr = new A();

}
 int main(){
    instantiate();
 }

/*output:
A instantiated
*/ 
