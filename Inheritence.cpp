// Inheritance
// All 3 from same laptop family, but they have different specification (variations). So 3 different classes.

#include <string>
using namespace std;

class Laptop{
    private:
    string modelName;               // all these are common parameters of the 3 laptops so kept in single class.
    string serialNumber;
    float color;
    float weight;
    string hostOs;   
    int storageCapacity;
};

class HPLaptop : public Laptop {    // "is a relation = inheritance". HP laptop "is a" kind of laptop. 
                                // compile time / static relationship. If obj of HpLaptop is created, it contains data members of Laptop class
};
class ZeLaptop {
     
};
class LenvoLaptop {
     
};

int main() {
    //Laptop obj;     //never create obj of base class. Because in the above ex. we have either HP/Len/Ze but not any kind of Laptop
                      // Now we need to reuse the code for Laptop but it should not be instantiate(don't create object)
                      // can create a pointer of base class
    // So Solution is marking the Constuctor as PROTECTED. Means Private to outside, visible to derived classes.
    return 0;
}
