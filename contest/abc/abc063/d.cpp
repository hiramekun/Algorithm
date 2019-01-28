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

ll n, a, b;
vector<ll> h;

void solve() {
    ll st = 0, end = ll(1e9);
    while (end - st > 1) {
        ll c = 0;
        ll center = (end + st) / 2;
        each(i, h) {
            if (i - b * center > 0) c += ceil(double(i - b * center) / (a - b));
        }
        if (c <= center) end = center;
        else st = center;
    }
    cout << end << endl;
}

int main() {
    cin >> n >> a >> b;
    rep(i, n) {
        ll temp;
        cin >> temp;
        h.emplace_back(temp);
    }
    solve();
    return 0;
}
