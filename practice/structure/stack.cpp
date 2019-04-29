#include <iostream>

class Stack {
    private:
        int sz;
        static const int MAX_SIZE = 1000;
        int stack[MAX_SIZE];

    public:
        Stack () {
            sz = 0;
        }
        void push(int x) {
            stack[sz++] = x;
        }

        int back() {
            return stack[sz - 1];
        }

        void pop() {
            stack[sz--] = -1;
        }

        int size() {
            return sz;
        }
};

using namespace std;
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.back() << endl;
    s.pop();
    cout << s.back() << endl;
    cout << s.size() << endl;
    s.pop();
    cout << s.size() << endl;
}
