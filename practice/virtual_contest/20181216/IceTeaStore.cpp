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


ll q, h, s, d, n;

void solve() {
    ll min_one = min(q * 4, min(h * 2, s));
    if (min_one * 2 > d) {
        cout << d * (n / 2) + (n - 2 * (n / 2)) * min_one << endl;
    } else {
        cout << min_one * n << endl;
    }
}

int main() {
    cin >> q >> h >> s >> d >> n;
    solve();
    return 0;
}
