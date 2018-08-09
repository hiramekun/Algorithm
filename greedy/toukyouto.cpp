//
// Created by Takaaki Hirano on 2018/08/01.
//
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_T = 100;
int T;
string S[MAX_T];

void solve() {
    for (int t = 0; t < T; t++) {
        int sum = 0;
        int i = 0;
        while (i < S[t].length()) {
            string substring = S[t].substr(i, 5);
            if (substring == "tokyo" || substring == "kyoto") {
                i += 5;
                sum++;
            } else {
                i++;
            }
        }

        printf("%d\n", sum);
    }
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> S[t];
    }
    solve();
}
