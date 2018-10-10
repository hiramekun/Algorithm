#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_S = 10;
int s_len, s_dig[MAX_S];

int each_digit(int S) {
    while (S > 0) {
        s_dig[s_len++] = S % 10;
        S /= 10;
    }
}

int main() {
    int S;
    cin >> S;
    each_digit(S);
    return 0;
}
