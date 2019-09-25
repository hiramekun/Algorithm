#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define each(i, mp) for(auto i:mp)
typedef long long ll;
const int MAX_S = 10;
int s_len, s_dig[MAX_S];


// if n = 123
// ret[0] = 3, ret[1] = 2, ret[2] = 1;
vector<int> each_digit(ll n) {
    vector<int> ret;
    while (n > 0) ret.emplace_back(n % 10), n /= 10;
    return ret;
}

int main() {
    int S;
    cin >> S;
    vector<int> ans = each_digit(S);
    each(m, ans) {
        cout << m << endl;
    }
    return 0;
}
