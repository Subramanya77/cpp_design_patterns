//Dictionary
//Dictionary contains vector of objects of type key value pair

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename K, typename V>
class KeyValuePair{
    public:
    K key;
    V value;
};

template<typename K, typename V>
class Dictionary {
    Vector<KeyValuePair<K,V>> KeyValuePairs;
    public:
        void add(K key, V value){

        }
};

int main() {
    Dictionary<string, string> stringMap;
    stringMap.add("BLR", "Bengaluru");
    stringMap.add("CHE", "Chennai");
    string value = stringMap["BLR"];
    cout << value << endl;

    Dictionary<string, int> stringToIntMap;
    stringToIntMap.add("one", 1);
    stringToIntMap.add("two", 2);
    int number = stringToIntMap["One"];
    cout << number << endl;
}
