#include <string>
#include <iostream>

using namespace std;

struct Key {
    string str;

    Key() = default;

    explicit Key(string s) {
        str = s;
    }

    bool equals(Key k) const {
        return k.str == str;
    }

    int hash_code() {
        int sum = 0;
        for (int i = 0; i <= str.size(); i++) {
            sum += (int) str[i];
        }
        return sum;
    }
};

struct Node {
    Key key;
    int data;
    Node *next;

    Node(Key key, int data) {
        this->key = key;
        this->data = data;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int DEFAULT = 10;
    Node *table[DEFAULT]{};
    int sz;

    int hash(Key key) {
        return key.hash_code() % DEFAULT;
    }

public:
    HashTable() {
        for (auto &i : table) {
            i = nullptr;
        }
        sz = 0;
    }

    int find(const Key &key) {
        for (Node *p = table[hash(key)]; p != nullptr; p = p->next) {
            if (key.equals(p->key)) {
                return p->data;
            }
        }
        return -1;
    }

    bool insert(const Key &key, int data) {
        if (find(key) != -1) {
            return false;
        }
        Node *p = new Node(key, data);
        int h = hash(key);
        p->next = table[h];
        table[h] = p;
        sz++;

        return true;
    }
};

int main() {
    HashTable table;
    Key k1("hi");
    Key k2("hi2");
    Key k3("ih");
    table.insert(k1, 1);
    table.insert(k2, 100);
    table.insert(k3, 1000);
    cout << table.find(k2) << endl;
    cout << table.find(k3) << endl;
    return 0;
}
