#include <cstring>
#include <sstream>
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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef pair<ll, ll> P;
typedef map<pair<ll, ll>, ll> ump;

ump mp;
ll n, k, l;
const ll MAX_V = 2 * half_inf;

vector<ll> G_k[MAX_V];
bool see_k[MAX_V];
ll num_k[MAX_V];
vector<ll> G_l[MAX_V];
bool see_l[MAX_V];
ll num_l[MAX_V];

void dfs_k(ll s, ll num) {
    see_k[s] = true;
    num_k[s] = num;
    rep(i, G_k[s].size()) {
        if (!see_k[G_k[s][i]]) dfs_k(G_k[s][i], num);
    }
}

void dfs_l(ll s, ll num) {
    see_l[s] = true;
    num_l[s] = num;
    rep(i, G_l[s].size()) {
        if (!see_l[G_l[s][i]]) dfs_l(G_l[s][i], num);
    }
}

void solve() {
    ll nk = 1;
    rep(i, n) {
        if (!see_k[i]) {
            dfs_k(i, nk);
            nk++;
        }
    }
    ll nl = 1;
    rep(i, n) {
        if (!see_l[i]) {
            dfs_l(i, nl);
            nl++;
        }
    }

    rep(i, n) mp[make_pair(num_k[i], num_l[i])]++;
    rep(i, n) {
        printf("%d ", mp[make_pair(num_k[i], num_l[i])]);
    }
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> n >> k >> l;
        rep(i, k) {
            ll p, q;
            cin >> p >> q;
            p--, q--;
            G_k[p].emplace_back(q);
            G_k[q].emplace_back(p);
        }

        rep(i, l) {
            ll r, s;
            cin >> r >> s;
            r--, s--;
            G_l[r].emplace_back(s);
            G_l[s].emplace_back(r);
        }

        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}