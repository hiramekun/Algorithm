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

class DAG {
private:
    ll v, e;
    vvl table;
    vl d; // 各頂点の次数
public:
    // v: 頂点数
    // e: 辺の数
    DAG(ll v, ll e) : v(v), e(e) {
        table.resize(v);
        d.resize(v);
    }

    // 0-index
    void add(ll from, ll to) {
        table[from].eb(to);
        d[from]++, d[to]++;
    }

    // 準オイラーグラフが存在するかどうか
    // is_circle = true にした場合、オイラー閉路が存在するか
    // オイラーグラフとは、全ての辺を一回ずつ使用するもの
    bool has_euler_trail(bool is_circle) {
        ll even = 0, odd = 0;
        each(ele, d) {
            if (ele % 2 == 0)even++;
            else odd++;
        }
        if (is_circle && odd == 0) return true;
        if (!is_circle && odd == 2) return true;

        return false;
    }

    vl get_trail(const ll s, vvl &g, const bool directed) {
        auto dfs = [&](auto &&f, ll u, vl &trail) -> void {
            while (!g[u].empty()) {
                ll now = g[u].back();
                g[u].pop_back();

                if (!directed) {
                    for (ll i = 0; i < g[now].size(); ++i) {
                        if (g[now][i] == u) {
                            g[now].erase(g[now].begin() + i);
                            break;
                        }
                    }
                }

                f(f, now, trail);
            }
            trail.eb(u);
        };
        vl trail;
        dfs(dfs, s, trail);
        reverse(all(trail));

        return move(trail);
    }
};

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif


#ifdef MY_DEBUG
    }
#endif
    return 0;
}
