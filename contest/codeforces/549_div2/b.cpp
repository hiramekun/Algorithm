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

// if n = 123
// ret[0] = 3, ret[1] = 2, ret[2] = 1;
vector<ll> each_digit(ll n) {
    vector<ll> ret;
    while (n > 0) ret.emplace_back(n % 10), n /= 10;
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
        vector<ll> table = each_digit(n);
        if (table.size() == 1) cout << n << endl;
        else {
            ll ans = 1;
            int maxid = -1;
            int max9 = -1;
            for (int i = table.size() - 2; i >= 0; --i) {
                if (maxid == -1 && table[i] != 9) {
                    maxid = i;
                }
                if (max9 == -1 && table[i] == 9) {
                    max9 = i;
                }
            }
            ll tmp = 1;
            ll tmp2 = 1;
            ll tmp3 = 1;
            for (int i = 0; i < table.size(); ++i) {
                if (i <= maxid) tmp *= 9;
                else if (i == maxid + 1) {
                    if (table[i] != 1) tmp *= (table[i] - 1);
                } else tmp *= table[i];

                if (i < maxid) tmp2 *= 9;
                else if (i == maxid) {
                    if (table[i] != 1) tmp2 *= (table[i] - 1);
                } else tmp2 *= table[i];

                if (i < max9) tmp3 *= 9;
                else if (i == max9) tmp3 *= 8;
                else tmp3 *= table[i];
            }
            ll tmp4 = 1;
            if (table.back() != 1) tmp4 *= (table.back() - 1);
            for (int i = 1; i < table.size(); ++i) {
                tmp4 *= 9;
            }
            ans = max({tmp, tmp2, tmp3, tmp4});
            cout << ans << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}