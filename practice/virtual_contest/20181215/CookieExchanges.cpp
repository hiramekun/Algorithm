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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

ll a, b, c;

void solve() {
    if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    if (a == b && b == c) {
        cout << -1 << endl;
        return;
    }

    ll ab = a + b, bc = b + c, ca = c + a;
    ll t_ab = 0, t_bc = 0, t_ca = 0;
    while (ab % 2 == 0) ab /= 2, t_ab++;
    while (bc % 2 == 0) bc /= 2, t_bc++;
    while (ca % 2 == 0) ca /= 2, t_ca++;
    cout << min(min(t_ab, t_bc), t_ca) << endl;
}

int main() {
    cin >> a >> b >> c;
    solve();
    return 0;
}
