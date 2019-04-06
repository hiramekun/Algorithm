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
        ll t;
        cin >> t;
        vector<ll> n(t);
        vector<string> p(t);
        rep(i, t) {
            cin >> n[i] >> p[i];
        }

        rep(i, t) {
            string ans;
            if (p[i][0] == 'E' && p[i].back() == 'S') {
                ans = string(n[i] - 1, 'S') + string(n[i] - 1, 'E');
            }
            if (p[i][0] == 'E' && p[i].back() == 'E') {
                P op(0, 0), me(0, 0); // E, W
                ll goe = 0;
                for (int j = 0; j < p[i].size() - 1; ++j) {
                    if (p[i][j] == 'E') op.first++;
                    else {
                        op.second++;
                        if (p[i][j + 1] == 'S') {
                            goe = op.second;
                            break;
                        }
                    }
                }
                for (int j = 0; j < p[i].size(); ++j) {
                    if (me.second < goe) ans += 'S', me.second++;
                    else if (me.second == goe) {
                        ans += string(n[i] - 1, 'E');
                        j += n[i] - 1;
                        me.second++;
                        ans += 'S';
                    } else {
                        ans += 'S';
                    }
                }
            }
            if (p[i][0] == 'S' && p[i].back() == 'E') {
                ans = string(n[i] - 1, 'E') + string(n[i] - 1, 'S');
            }
            if (p[i][0] == 'S' && p[i].back() == 'S') {
                P op(0, 0), me(0, 0); // E, W
                ll goe = 0;
                for (int j = 0; j < p[i].size() - 1; ++j) {
                    if (p[i][j] == 'S') op.second++;
                    else {
                        op.first++;
                        if (p[i][j + 1] == 'E') {
                            goe = op.first;
                            break;
                        }
                    }
                }
                for (int j = 0; j < p[i].size(); ++j) {
                    if (me.first < goe) ans += 'E', me.first++;
                    else if (me.first == goe) {
                        ans += string(n[i] - 1, 'S');
                        j += n[i] - 1;
                        me.first++;
                        ans += 'E';
                    } else {
                        ans += 'E';
                    }
                }
            }
            cout << "Case #" << i + 1 << ": " << ans << endl;
        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}