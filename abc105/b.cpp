#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N;

void solve() {
    int a, b = 0;
    a = N / 4;
    b = N / 7;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (4 * i + 7 * j == N) {
                printf("Yes\n");
                return;
            }
        }
    }
    printf("No\n");
}

int main() {
    cin >> N;
    solve();
    return 0;
}

