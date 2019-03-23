#include <cstring>
#include <iterator>
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
        ll n;
        cin >> n;
        vector<ll> b;
        rep(i, n) {
            ll temp;
            cin >> temp;
            b.emplace_back(temp);
        }

        vector<ll> ans;
        for (ll i = n; i >= 1; i--) {
            vector<ll> a;
            bool has = false;
            ll elem = 0, idx = 0;
            repr(j, b.size()) {
                if (b[j] <= i && b[j] == (j + 1)) {
                    if (b[j] >= elem) {
                        elem = b[j];
                        idx = j;
                    }
                    has = true;
                }
            }

            if (!has) {
                cout << -1 << endl;
                return 0;
            }
            rep(j, b.size()) {
                if (j != idx) a.emplace_back(b[j]);
                else ans.emplace_back(b[j]);
            }
            b = a;
        }

        repr(i, n) printf("%lli ", ans[i]);

#ifdef MY_DEBUG
    }
#endif
    return 0;
}