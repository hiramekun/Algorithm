#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
int A, B;

void solve() {
    printf("%d\n", A * B - A - B + 1);
}

int main() {
    cin >> A >> B;
    solve();
    return 0;
}

