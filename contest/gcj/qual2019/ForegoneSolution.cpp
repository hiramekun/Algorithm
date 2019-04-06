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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;

//// if n = 123
//// ret[0] = 3, ret[1] = 2, ret[2] = 1;
//vector<ll> each_digit(ll n) {
//    vector<ll> ret;
//    while (n > 0) ret.emplace_back(n.back() - '0'), n.pop_back();
//    return ret;
//}

// if n = 123
// ret[0] = 3, ret[1] = 2, ret[2] = 1;
vector<ll> each_digit(ll n) {
    vector<ll> ret;
    while (n > 0) ret.emplace_back(n % 10), n /= 10;
    return ret;
}

string vec_to_string(vector<ll> v) {
    string ret;
    each(m, v) ret += to_string(m) + ret;
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
        ll t;
        cin >> t;
        vector<ll> n(t);
        rep(i, t) cin >> n[i];

        rep(i, t) {
            ll ans1 = n[i], ans2 = 0;
            ll idx = 0;
            while (n[i] > 0) {
                ll tmp = n[i] % 10;
                if (tmp == 4) ans1 -= 2 * ll(pow(10, idx)), ans2 += 2 * ll(pow(10, idx));
                idx++;
                n[i] /= 10;
            }
            cout << "Case #" << i + 1 << ": " << ans1 << " " << ans2 << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}