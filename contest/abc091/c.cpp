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

int n;
vector<P> ab, cd;

void solve() {
    sort(ab.begin(), ab.end(), [](P a, P b) { return a.second > b.second; });
    sort(cd.begin(), cd.end());
    int ans = 0;
    bool used[n];
    fill(used, used + n, false);
    rep(i, n) {
        P _xy = cd[i];
        rep(j, n) {
            P xy = ab[j];
            if (!used[j] && xy.first < _xy.first && xy.second < _xy.second) {
                used[j] = true;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    ab.resize(n);
    cd.resize(n);
    int x, y;
    rep(i, n) {
        cin >> x >> y;
        ab[i] = make_pair(x, y);
    }
    rep(i, n) {
        cin >> x >> y;
        cd[i] = make_pair(x, y);
    }
    solve();
    return 0;
}
