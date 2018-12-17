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
#define inf int(1e9)
#define half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

const int max_n = half_inf;
ll n, k;
vector<ll> a;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    if (k > *max_element(a.begin(), a.end())) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    ll n_gcd = a[0];
    repone(i, n - 1) n_gcd = gcd(n_gcd, a[i]);
    if (k % n_gcd == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
    solve();
    return 0;
}
