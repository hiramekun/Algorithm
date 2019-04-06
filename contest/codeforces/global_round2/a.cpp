#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
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
#define eb emplace_back
#define F first
#define S second
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef pair<ll, ll> P;
typedef vector<ll> vll;

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n;
        cin >> n;
        vll c(n);
        P i_small1, i_small2;
        P i_large1, i_large2;
        rep(i, n) {
            cin >> c[i];
        }
        i_small1 = make_pair(0, c[0]);
        rep(i, n) if (c[i] != c[0]) {
                i_small2 = make_pair(i, c[i]);
                break;
            }

        i_large1 = make_pair(n - 1, c.back());
        repr(i, n) if (c[i] != c.back()) {
                i_large2 = make_pair(i, c[i]);
                break;
            }
        ll ans = 0;
        rep(i, n) {
            if (c[i]== i_small1.S) ans = max(ans, abs(i - i_small2.F));
            if (c[i]!= i_small1.S) ans = max(ans, abs(i - i_small1.F));
            if (c[i]== i_large1.S) ans = max(ans, abs(i - i_large2.F));
            if (c[i]!= i_large1.S) ans = max(ans, abs(i - i_large1.F));
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}