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


class UnionFind {
private:
    vector<ll> par; // 親
    vector<ll> rank; // 木の深さ

    // 木の根を求める
    ll find(ll x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

public:
    explicit UnionFind(unsigned int n) {
        par.resize(n);
        rank.resize(n);
        rep(i, n) {
            par[i] = i;
            rank[i] = 0;
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


vector<ll> p;
int N, E;

int main() {
    cin >> N >> E;
    p.resize(N);

    UnionFind tree = UnionFind(N);
    rep(i, N) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        tree.unite(s - 1, t - 1);
    }

    ll ans = 0;
    rep(i, N) {
        if (tree.is_same(i, p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}
