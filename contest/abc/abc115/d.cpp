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
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll n, x;
ll p[50], a[50];

// レベルnのバーガーの下からxそうに含まれるパティの枚数
ll f(ll n, ll x) {
    if (n == 0) return x <= 0 ? 0 : 1;
    else if (x <= 1 + a[n - 1]) return f(n - 1, x - 1);
    else if (x == 2 + a[n - 1]) return 1 + p[n - 1];
    else return p[n - 1] + 1 + f(n - 1, x - 2 - a[n - 1]);
}


void solve() {
    p[0] = 1, a[0] = 1;
    repone(i, n - 1) {
        p[i] = 2 * p[i - 1] + 1;
        a[i] = 2 * a[i - 1] + 3;
    }
    cout << f(n, x) << endl;
}

int main() {
    cin >> n >> x;
    solve();
    return 0;
}
