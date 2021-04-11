#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int a[] = {1, 2, 3, 3, 4, 5}; // ソートされていること (重要)
    int n = sizeof(a) / sizeof(int);

    int *lb = lower_bound(a, a + n, 3); // min(i | a[i] >= 3) となる a[i] へのポインタ
    int *ub = upper_bound(a, a + n, 3); // min(i | a[i] > 3) となる a[i] へのポインタ

    cout << *lb << endl; //=> 3
    cout << *ub << endl; //=> 4
    cout << ub - lb << endl; //=> 2 ('3' の個数; ポインタ同士の減算)

    return 0;
}

