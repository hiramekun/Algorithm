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

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


int n;
vector<int> a, b, c;
int abc[half_inf + 100][3];

void solve() {
    ll dp[half_inf + 100][3];
    rep(i, half_inf + 100) rep(j, 3) dp[i][j] = 0;
    rep(i, n) {
        rep(j, 3) {
            rep(k, 3) {
                if (j == k) continue;
                chmax(dp[i + 1][j], dp[i][k] + abc[i][j]);
            }
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}

int main() {
    cin >> n;
    a.resize(n), b.resize(n), c.resize(n);
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        abc[i][0] = a[i];
        abc[i][1] = b[i];
        abc[i][2] = c[i];
    }
    solve();
    return 0;
}
