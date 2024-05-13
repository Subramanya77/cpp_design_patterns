#include <iostream>
#include <string>
using namespace std;

class TextBox {
    public:
        virtual void accept(string text){
            cout << "Text box accept" <<endl;
        }
};
class NumericTextBox : public TextBox {     //SHADOWING - contains same method accept() from base class.
    public:
        void accept(string text) override {
            cout << "Numeric box accept" <<endl;
        }
};
class MaskedTextBox : public TextBox {    
    public:
        void accept(string text) override{
            cout << "Masked box accept" <<endl;
        }
};

 int main(){
    TextBox nameTextBox;
    nameTextBox.accept("Tom");

    NumericTextBox ageTextBox;
    ageTextBox.accept("25");       

    TextBox* basePtr = &ageTextBox;
    basePtr->accept("35");

    MaskedTextBox phoneNumberTextBox;
    basePtr=&phoneNumberTextBox;
    basePtr ->accept("91-1231231231");

 }
