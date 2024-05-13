//VECTOR program from above using template
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Device {
public:
    string name;

    // Overload the << operator to print Device objects
    friend ostream& operator<<(ostream& os, const Device& d) {
        os << d.name;
        return os;
    }
};

template <typename T>
class Vector {
private:
    vector<T> items;

public:
    void push_back(T item) {
        items.push_back(item);
    }

    friend ostream& operator<<(ostream& os, const Vector<T>& v) {
        os << "[";
        for (size_t i = 0; i < v.items.size(); ++i) {
            os << v.items[i];
            if (i != v.items.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    Vector<string> vs;
    vs.push_back("A10");
    vs.push_back("A20");

    Vector<Device> vd;
    Device obj1;
    obj1.name = "D1";
    Device obj2;
    obj2.name = "D2";
    vd.push_back(obj1);
    vd.push_back(obj2);

    cout << "Int Vector: " << v << endl;
    cout << "String Vector: " << vs << endl;
    cout << "Device Vector: " << vd << endl;

    return 0;
}

//output
/*
Int Vector: [10, 20]
String Vector: [A10, A20]
Device Vector: [D1, D2]
*/
