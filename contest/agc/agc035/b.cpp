#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using v = vector<T>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
void dump_debug(T list) {
#ifdef MY_DEBUG
    each(e, list) cout << e << " ";
    printf("\n");
#endif
}

inline ll inl() {
    ll x;
    cin >> x;
    return x;
}

inline string ins() {
    string x;
    cin >> x;
    return x;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
class UnionFind {
private:
    vector<ll> size; // グループに属する物の数．
public:
    vector<ll> par; // 親
    vector<ll> rank; // 木の深さ

    explicit UnionFind(unsigned int n) {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        rep(i, n) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
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

    // グループのサイズを求める．
    ll calc_size(ll x) {
        return size[find(x)];
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
            if (rank[x] == rank[y])rank[x]++;
        }
        size[x] = size[y] = size[x] + size[y];
    }

    // xとyが同じ集合に属するか否か
    bool is_same(ll x, ll y) {
        return find(x) == find(y);
    }
};


int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        ll n, m;
        cin >> n >> m;
        v<P> ab(m);
        rep(i, m) {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            ab[i] = {a, b};
        }

        if (m % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }

        UnionFind uf(n);
        v<bool> used(m);

        // 全域木に使う辺を見つける
        v<v<P>> g(n, v<P>());
        rep(i, m) {
            ll a = ab[i].F, b = ab[i].S;
            if (uf.is_same(a, b)) continue;
            uf.unite(a, b);
            used[i] = true;
            g[a].eb(make_pair(b, i));
            g[b].eb(make_pair(a, i));
        }

        // 全域木に使わない辺を適当に設定
        vl outn(n);
        rep(i, m) {
            if (used[i]) continue;
            ll a = ab[i].F, b = ab[i].S;
            cout << a + 1 << " " << b + 1 << endl;
            outn[a]++;
        }

        // 全域木に使う辺をうまい具合に構築
        v<bool> seen(n);

        auto dfs = [&](auto &&f, ll now) -> void {
            seen[now] = true;
            each(e, g[now]) {
                ll next = e.F, idx = e.S;
                if (!seen[next] && used[idx]) {
                    if (outn[now] % 2 != 0) {
                        cout << now + 1 << " " << next + 1 << endl;
                        outn[now]++;
                    } else {
                        cout << next + 1 << " " << now + 1 << endl;
                        outn[next]++;
                    }

                    f(f, next);
                }
            }
        };
        dfs(dfs, 0);

#ifdef MY_DEBUG
    }
#endif
    return 0;
}

