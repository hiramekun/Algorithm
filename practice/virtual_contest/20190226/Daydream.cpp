#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;

void solve() {
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        string s;
        cin >> s;
        int idx = s.length() - 1;
        while (idx > 0) {
            if (s[idx] == 'm') {
                if (idx >= 4 && s.substr(idx - 4, 5) == "dream") idx -= 5;
                else break;
            } else if (s[idx] == 'e') {
                if (idx >= 4 && s.substr(idx - 4, 5) == "erase") idx -= 5;
                else break;
            } else if (s[idx] == 'r') {
                if (idx >= 6 && s.substr(idx - 6, 7) == "dreamer") idx -= 7;
                else if (idx >= 5 && s.substr(idx - 5, 6) == "eraser") idx -= 6;
                else break;
            } else {
                break;
            }
            if (idx == -1) {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}