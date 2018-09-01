//
// Created by Takaaki Hirano on 2018/09/01.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>


using namespace std;
int K;

void solve() {
    int even = 0, odd = 0;
    for (int i = 1; i <= K; ++i) {
        if (i % 2 == 0)even++;
        else odd++;
    }

    printf("%d\n", even * odd);
}

int main() {
    cin >> K;
    solve();
    return 0;
}

