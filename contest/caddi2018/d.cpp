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
ll n, a[max_n];

void solve() {
    ll n_even = 0, n_odd = 0;
    ll n_one = 0, n_no_one = 0;
    rep(i, n) {
        if (a[i] % 2 == 0) n_even++;
        else n_odd++;
        if (a[i] == 1) n_one++;
        else n_no_one += a[i];
    }
    if (n_even == 0) {
        cout << "first" << endl;
    } else if (abs(n - n_even) % 2 != 0) {
        cout << "first" << endl;
    } else if (n != 1 && n_even <= n_odd) {
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }
}

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];
    solve();
    return 0;
}
