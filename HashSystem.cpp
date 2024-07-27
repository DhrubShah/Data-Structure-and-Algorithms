#include <iostream>
#define tableSize 15
using namespace std;
int hashFunction(int key) {
    return key % 15;
}

int hashTable[tableSize];

void insertKey(int key) {
    int index = hashFunction(key);
    if (hashTable[index] == 0) {
        hashTable[index] = key;
    }
    else {
        cout << "Collision occurred for key " << key<<endl;
    }
}

void displayHashTable() {
    cout << "Hash Table:\n";
    for (int i = 0; i < tableSize; ++i) {
        cout << i << ": ";
        if (hashTable[i] != 0) {
            cout << hashTable[i];
        }
        cout << endl;
    }
}

int main() {
    insertKey(10);
    insertKey(5);
    insertKey(20);
    displayHashTable();

    return 0;
}
