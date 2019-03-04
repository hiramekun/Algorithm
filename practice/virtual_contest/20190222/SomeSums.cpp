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
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

unordered_map<ll, ll> mp;

void solve() {
}

ll each_dig(string s) {
    ll ret = 0;
    rep(i, s.size()) {
        ret += (s[i] - '0');
    }
    return ret;
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = unordered_map<ll, ll>();
#pragma clang diagnostic pop
#endif
        int n, a, b;
        cin >> n >> a >> b;
        ll ans = 0;
        repone(i, n) {
            ll temp = each_dig(to_string(i));
            if (temp >= a && temp <= b) ans += i;
        }
        cout << ans << endl;

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}