#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
string S;
long long K;

void solve() {
    long long i = 0;
    while (S.at(static_cast<unsigned long>(i)) == '1') {
        i++;
        if (i == K) {
            printf("%c\n", '1');
            return;
        }
    }
    printf("%c\n", S.at(static_cast<unsigned long>(i)));
}

int main() {
    cin >> S >> K;
    solve();
    return 0;
}
