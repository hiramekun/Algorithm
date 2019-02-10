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
#include <numeric>

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

ll n, m;
typedef struct _cake {
    ll x, y, z;
} cake;

vector<cake> cs;

ll calc_ans(vector<cake> v, ll op1, ll op2, ll op3) {
    ll ret = 0;
    rep(i, m)ret += (v[i].x * op1 + v[i].y * op2 + v[i].z * op3);
    return ret;
}

void solve() {
    ll ans = 0;
    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return c1.x + c1.y + c1.z > c2.x + c2.y + c2.z; });
    ans = max(ans, calc_ans(cs, 1, 1, 1));

    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return c1.x + c1.y - c1.z > c2.x + c2.y - c2.z; });
    ans = max(ans, calc_ans(cs, 1, 1, -1));

    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return c1.x - c1.y + c1.z > c2.x - c2.y + c2.z; });
    ans = max(ans, calc_ans(cs, 1, -1, 1));

    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return -c1.x + c1.y + c1.z > -c2.x + c2.y + c2.z; });
    ans = max(ans, calc_ans(cs, -1, 1, 1));

    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return c1.x - c1.y - c1.z > c2.x - c2.y - c2.z; });
    ans = max(ans, calc_ans(cs, 1, -1, -1));

    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return -c1.x - c1.y + c1.z > -c2.x - c2.y + c2.z; });
    ans = max(ans, calc_ans(cs, -1, -1, 1));

    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return -c1.x + c1.y - c1.z > -c2.x + c2.y - c2.z; });
    ans = max(ans, calc_ans(cs, -1, 1, -1));

    sort(cs.begin(), cs.end(),
         [](cake c1, cake c2) { return -c1.x - c1.y - c1.z > -c2.x - c2.y - c2.z; });
    ans = max(ans, calc_ans(cs, -1, -1, -1));

    cout << ans << endl;
}


int main() {
    cin >> n >> m;
    cs.resize(n);
    rep(i, n) {
        ll x, y, z;
        cin >> x >> y >> z;
        cake c = {x, y, z};
        cs[i] = c;
    }
    solve();
    return 0;
}
