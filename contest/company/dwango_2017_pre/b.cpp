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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        string t;
        cin >> t;
        string te(t), to(t);
        ll ans = 0;
        rep(i, te.size()) {
            if (i % 2 == 0 && te[i] == '?') te[i] = '2';
            if (i % 2 != 0 && te[i] == '?') te[i] = '5';
        }
        ll idx = 0;
        ll tmp = 0;
        while (idx < te.size()) {
            if (idx % 2 == 0 && te[idx] == '2' && te[idx + 1] == '5') {
                tmp += 2;
                idx += 2;
            } else {
                ans = max(tmp, ans);
                tmp = 0;
                idx++;
            }
        }
        ans = max(tmp, ans);

        rep(i, to.size()) {
            if (i % 2 != 0 && to[i] == '?') to[i] = '2';
            if (i % 2 == 0 && to[i] == '?') to[i] = '5';
        }
        idx = 0;
        tmp = 0;
        while (idx < to.size()) {
            if (idx % 2 != 0 && to[idx] == '2' && to[idx + 1] == '5') {
                tmp += 2;
                idx += 2;
            } else {
                ans = max(tmp, ans);
                tmp = 0;
                idx++;
            }
        }
        ans = max(tmp, ans);
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}