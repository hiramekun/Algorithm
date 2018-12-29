#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N, K;

void solve() {
    if (N%K == 0) {
        printf("%d\n", 0);
    } else{
        printf("%d\n", 1);
    }
}

int main() {
    cin >> N >> K;
    solve();
    return 0;
}

