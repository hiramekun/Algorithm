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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        int t;
        cin >> t;
        vector<string> s(t);
        vector<int> k(t);
        rep(i, t) cin >> s[i] >> k[i];

        rep(i, t) {
            int ans = 0;
            vector<int> ansv(s[i].size());
            rep(j, s[i].size()) {
                if (s[i][j] == '-') ansv[j] = 1;
                else ansv[j] = 0;
            }
            rep(j, s[i].size()) {
                if (ansv[j] % 2 == 0) continue;
                if (ansv[j] % 2 != 0) {
                    if (j <= s[i].size() - k[i]) {
                        rep(l, k[i]) ansv[j + l]++;
                        ans++;
                    } else {
                        repr(l, k[i]) ansv[ansv.size() - k[i] + l]++;
                        ans++;
                    }
                }
            }
            bool b = false;
            rep(j, s[i].size()) if (ansv[j] % 2 != 0) {
                    cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
                    b = true;
                    break;
                }

            if (b) continue;
            cout << "Case #" << i + 1 << ": " << ans << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}