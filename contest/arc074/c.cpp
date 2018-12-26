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


ll h, w;

void solve() {
    ll longer = max(h, w);
    ll shorter = min(h, w);
    ll ans = ll_inf;
    if (h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
        return;
    }
    repone(i, longer - 1) {
        if (shorter % 2 == 0) ans = min(abs(shorter * (i) - (longer - i) * (shorter / 2)), ans);
        else {
            ans = min(max({abs(shorter * (i) - (longer - i) * (shorter / 2)),
                           abs(shorter * (i) - (longer - i) * (shorter / 2 + 1)),
                           abs((longer - i) * (shorter / 2) - (longer - i) * (shorter / 2 + 1))
                          }), ans);
        }
        if (longer - i % 2 == 0) ans = min(abs(shorter * i - (longer - i) / 2 * shorter), ans);
        else {
            ans = min(max({abs(shorter * i - (longer - i) / 2 * shorter),
                           abs(shorter * i - ((longer - i) / 2 + 1) * shorter),
                           abs((longer - i) / 2 * shorter - ((longer - i) / 2 + 1) * shorter)
                          }), ans);
        }
    };
    repone(i, shorter - 1) {
        if (longer % 2 == 0) ans = min(abs(longer * (i) - (shorter - i) * (longer / 2)), ans);
        else {
            ans = min(max({abs(longer * (i) - (shorter - i) * (longer / 2)),
                           abs(longer * (i) - (shorter - i) * (longer / 2 + 1)),
                           abs((shorter - i) * (longer / 2) - (shorter - i) * (longer / 2 + 1))
                          }), ans);
        }
        if (shorter - i % 2 == 0) ans = min(abs(longer * i - (shorter - i) / 2 * longer), ans);
        else {
            ans = min(max({abs(longer * i - (shorter - i) / 2 * longer),
                           abs(longer * i - ((shorter - i) / 2 + 1) * longer),
                           abs((shorter - i) / 2 * longer - ((shorter - i) / 2 + 1) * longer)
                          }), ans);
        }
    };
    cout << ans << endl;
}

int main() {
    cin >> h >> w;
    solve();
    return 0;
}
