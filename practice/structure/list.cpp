struct Node {
    Node *next;
    int value;
};

class LinkedList {
    private:
        int sz;
        Node *head;
    public:
        LinkedList() {
            head = nullptr;
            sz = 0;
        }

        void add(int x) {
            Node *node = new Node();
            node->next = nullptr;
            node->value = x;
            if (head == nullptr) {
                head = node;
            }
            else {
                Node *now = head;
                while(now->next != nullptr) now = now->next;
                now->next = node;
            }
            sz++;
        }

        void insert(int idx, int x) {
            Node *now;
            while(idx > 0) {
                now = now->next;
                idx--;
            }
            Node *node;
            node->value = x;
            node->next = now->next;
            now->next = node;
        }

        void remove(int idx) {
            if (idx == 0) head = head->next;
            else {
                Node *now = head;
                while(idx > 1) {
                    now = now->next;
                    idx--;
                }
                now->next = now->next->next;
            }

            sz--;
        }

        int at(int idx) {
            Node *now = head;
            while(idx > 0) {
                now = now->next;
                idx--;
            }
            return now->value;
        }
        
        int size() {
            return sz;
        }
};

#include <iostream>
using namespace std;

int main() {
    LinkedList list;
    for (int i = 0; i < 5; i++) {
        list.add(i);
    }
    
    for (int i = 0; i < 5; i++) {
        cout << list.at(i) << endl;
    }

    list.remove(2);
    for (int i = 0; i < list.size(); i++) {
        cout << list.at(i) << endl;
    }
    return 0;
}
