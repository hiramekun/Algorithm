//
// Created by Takaaki Hirano on 2018/07/31.
//

#include <cstdio>

using namespace std;

const int MAX_N = 50;

int N;
char S[MAX_N + 1];

void solve() {
    int a = 0, b = N - 1;

    while (a <= b) {
        bool left = false;
        for (int i = 0; a + i <= b; i++) {
            if (S[a + i] < S[b - i]) {
                left = true;
                break;
            } else if (S[a + i] > S[b - i]) {
                left = false;
                break;
            }
        }

        if (left) putchar(S[a++]);
        else putchar(S[b--]);
    }

    putchar('\n');
}

int main() {
    solve();
};
