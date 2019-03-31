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

int find(int a) {

}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n, q;
        string s;
        cin >> n >> q;
        cin >> s;
        char t[q], d[q];
        rep(i, q) cin >> t[i] >> d[i];

        ll is = -1;
        ll ie = n;
        WHILE:
        while (ie - is > 1) {
            ll m = (is + ie) / 2;
            ll tmp = m;
            char now = s[tmp];
            rep(i, q) {
                if (t[i] == now) {
                    if (d[i] == 'L') now = s[--tmp];
                    else now = s[++tmp];
                }
                if (tmp == -1) {
                    is = m;
                    goto WHILE;
                } else if (tmp == n) {
                    ie = m;
                    goto WHILE;
                }
            }
            ie = m;
        }
        ll ans = n;
        ans -= is;
        is = -1;
        ie = n;
        WHILE2:
        while (ie - is > 1) {
            ll m = (is + ie) / 2;
            ll tmp = m;
            char now = s[tmp];
            rep(i, q) {
                if (t[i] == now) {
                    if (d[i] == 'L') now = s[--tmp];
                    else now = s[++tmp];
                }
                if (tmp == -1) {
                    is = m;
                    goto WHILE2;
                } else if (tmp == n) {
                    ie = m;
                    goto WHILE2;
                }
            }
            is = m;
        }
        ans -= (n + 1 - ie);
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}