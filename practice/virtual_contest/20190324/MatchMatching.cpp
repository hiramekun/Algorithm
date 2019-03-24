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
#include <numeric>
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

ll getnum(ll x) {
    switch (x) {
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 6;
        default:
            throw "invalid number";
    }

}

string max_s(string s1, string s2) {
    if (s1.size() == s2.size()) return s1 > s2 ? s1 : s2;
    else return s1.size() > s2.size() ? s1 : s2;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n, m;
        cin >> n >> m;
        vector<ll> a(m);
        rep(i, m) cin >> a[i];

        string dp[n + 1];
        rep(i, n + 1) dp[i] = "-";
        dp[0] = "";
        rep(i, n + 1) {
            rep(j, a.size()) {
                if (i < getnum(a[j])) continue;
                if (dp[i - getnum(a[j])] == "-") continue;
                else {
                    dp[i] = max_s(dp[i - getnum(a[j])] + to_string(a[j]), dp[i]);
                }
            }
        }
        cout << dp[n] << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}