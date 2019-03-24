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

ll mul_mod(ll x, ll n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    ll ret = 1;
    while (n > 0) {
        ret *= x;
        ret %= mod;
        n--;
    }
    return ret;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n;
        cin >> n;
//        ll ans = 0;
//        ans += mul_mod(4, n);
//        ans += mul_mod(4, n) - ((n - 2) * 3 * mul_mod(4, n - 3) % mod) -
//               ((n - 3) * mul_mod(4, n - 4) * 2 % mod) - ((n - 3) * mul_mod(4, n - 4) * 2 % mod);
//        cout << ans << endl;

        ll dp3[n];

        ll ans3[n - 2];
        fill(ans3, ans3 + n - 2, 0);
        rep(i, n - 2) {
            if (n >= 4 && i >= 3) {
                dp3[i] = mul_mod(4, n - 4) * 11 - ans3[i - 3];
            } else if (i >= 3) {
                dp3[i] = mul_mod(4, n - 3) * 12 - ans3[i - 3];
            } else {
                if (n >= 4) dp3[i] = mul_mod(4, n - 4) * 11;
                else dp3[i] = mul_mod(4, n - 3) * 3;
            }
            if (i == 0) ans3[i] = dp3[i];
            else ans3[i] = ans3[i - 1] + dp3[i];
        }


        if (n > 3) {
            ll dp4[n];
            ll ans4[n - 3];
            fill(ans4, ans4 + n - 3, 0);
            rep(i, n - 3) {
                if (i >= 4) dp4[i] = 3 * mul_mod(4, n - 4) - ans4[i - 4];
                else dp4[i] = 3 * mul_mod(4, n - 4);
                if (i == 0) ans4[i] = dp4[i];
                else ans4[i] = ans4[i - 1] + dp4[i];
            }
            cout << mul_mod(4, n) - ans3[n - 3] - ans4[n - 4] << endl;
        } else {
            cout << mul_mod(4, n) - ans3[n - 3] << endl;
        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}