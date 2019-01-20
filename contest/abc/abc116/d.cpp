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
typedef pair<ll, ll> P;
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

class UnionFind {
public:
    vector<ll> par; // 親
    vector<ll> rank; // 木の深さ

    explicit UnionFind(unsigned int n) {
        par.resize(n);
        rank.resize(n);
        rep(i, n) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    // 木の根を求める
    ll find(ll x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // xとyの属する集合を併合
    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    // xとyが同じ集合に属するか否か
    bool is_same(ll x, ll y) {
        return find(x) == find(y);
    }
};


ll n, k;
vector<P> td;

void solve() {
    sort(td.begin(), td.end(), [](P a, P b) { return a.second > b.second; });
    UnionFind u = UnionFind(n);
    ll ans = 0;
    map<ll, ll> vari;
    ll vari_c = 0;
    rep(i, k - 1) {
        u.unite(td[i].first, td[i + 1].first);
        ans += td[i].second;
        if (vari[td[i].first] == 0) vari_c++;
        vari[td[i].first]++;
    }
    ans += (vari_c * vari_c);
    for (ll i = k; i < n; ++i) {
        if (vari[td[i].first] == 0) {
            ans -= td[k - 1 - (i - k)].second;
        }
    }
}

int main() {
    cin >> n >> k;
    td.resize(n);
    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        td[i] = make_pair(t, d);
    }
    solve();
    return 0;
}
