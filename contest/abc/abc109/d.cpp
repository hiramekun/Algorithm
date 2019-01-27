#include <cstring>
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
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);


int h, w;
int a[500][500];

void solve() {
    int ans = 0;
    vector<pair<int, int>> from, to;
    rep(i, h) {
        rep(j, w) {
            if (i == h - 1 && j == w - 1) {
                goto LABEL;
            }

            if (i % 2 == 0) {
                if (j == w - 1) {
                    if (a[i][j] % 2 != 0) {
                        a[i][j]--, a[i + 1][j]++;
                        ans++;
                        from.emplace_back(make_pair(i, j));
                        to.emplace_back(make_pair(i + 1, j));
                    }
                } else {
                    if (a[i][j] % 2 != 0) {
                        a[i][j]--, a[i][j + 1]++;
                        ans++;
                        from.emplace_back(make_pair(i, j));
                        to.emplace_back(make_pair(i, j + 1));
                    }
                }
            } else {
                int rev = w - 1 - j;
                if (rev == 0) {
                    if (a[i][rev] % 2 != 0) {
                        a[i][rev]--, a[i + 1][rev]++;
                        ans++;
                        from.emplace_back(make_pair(i, rev));
                        to.emplace_back(make_pair(i + 1, rev));
                    }
                } else {
                    if (a[i][rev] % 2 != 0) {
                        a[i][rev]--, a[i][rev - 1]++;
                        ans++;
                        from.emplace_back(make_pair(i, rev));
                        to.emplace_back(make_pair(i, rev - 1));
                    }
                };
            }
        }
    }
    LABEL:;
    cout << ans << endl;
    rep(i, from.size()) printf("%d %d %d %d\n", from[i].first + 1, from[i].second + 1,
                               to[i].first + 1,
                               to[i].second + 1);
}

int main() {
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> a[i][j];
    solve();
    return 0;
}
