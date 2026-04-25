#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    vector<int> table;
    int m;

public:
    HashTable(int size) {
        m = size;
        table.assign(m, -1);
    }

    int hashFunction(int key) {
        return key % m;
    }

    void insert(int key) {
        int h = hashFunction(key);

        for (int i = 0; i < m; i++) {
            int index = (h + i * i) % m;

            if (table[index] == -1) {
                table[index] = key;
                return;
            }
        }

        cout << "Hash Table Full\n";
    }

    void search(int key) {
        int h = hashFunction(key);

        for (int i = 0; i < m; i++) {
            int index = (h + i * i) % m;

            if (table[index] == -1) {
                cout << "NOT FOUND\n";
                return;
            }

            if (table[index] == key) {
                cout << "FOUND\n";
                return;
            }
        }

        cout << "NOT FOUND\n";
    }
};

int main() {
    int m, q;
    cin >> m >> q;

    HashTable ht(m);

    while (q--) {
        string op;
        int key;
        cin >> op >> key;

        if (op == "INSERT") {
            ht.insert(key);
        }
        else if (op == "SEARCH") {
            ht.search(key);
        }
    }

    return 0;
}