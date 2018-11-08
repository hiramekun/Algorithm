#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAX_S = 10;
int s_len, s_dig[MAX_S];


// 1234 -> 4 3 2 1
vector<int> each_digit(ll S) {
    int n_len = 0, n_dig[MAX_S];
    while (S > 0) {
        n_dig[n_len++] = S % 10;
        S /= 10;
    }
    vector<int> ret(n_dig, n_dig + n_len);
    return ret;
}

int main() {
    int S;
    cin >> S;
    each_digit(S);
    return 0;
}
