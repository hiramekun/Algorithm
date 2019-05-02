void swap(int &a, int &b) {
    int tep = a;
    a = b;
    b = tep;
}

#include <iostream>
using namespace std;
int main() {
    int a = 5, b = 6;
    swap(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}
