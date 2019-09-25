#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
using vb = vector<bool>;
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
void dumplist_debug(T list) {
#ifdef MY_DEBUG
    each(e, list) cout << e << " ";
    printf("\n");
#endif
}

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

string ins() {
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
    vl in_d; // 頂点の入力次数
public:
    // v: 頂点数
    // e: 辺の数
    DAG(ll v, ll e) : v(v), e(e) {
        table.resize(v);
        in_d.resize(v);
    }

    void add(ll from, ll to) {
        table[from].eb(to);
        in_d[to]++;
    }

    // O(v + e)
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    vl sort() {
        stack<ll> st; // 入力次数が0の頂点集合

        dumplist_debug(in_d);
        rep(i, v) if (in_d[i] == 0) st.push(i);
        vl ans; // ソート後のグラフ

        while (!st.empty()) {
            ll i = st.top();
            st.pop();
            ans.eb(i);
            each(j, table[i]) {
                in_d[j]--;
                if (in_d[j] == 0) st.push(j);
            }
        }

        return move(ans);
    }

    // O(v + e)
    // トポロジカル順序で最長経路を返す
    ll get_longest_path() {
        vb seen(v), calc(v);
        vl d(v, 0);
        auto dfs = [&](auto &&f, ll now) -> ll {
            if (seen[now]) {
                if (!calc[now]) return -1;
                return d[now];
            }
            seen[now] = true;
            d[now] = 1;
            each(t, table[now]) {
                ll res = f(f, t);
                if (res == -1) return -1;
                d[now] = max(res + 1, d[now]);
            }
            calc[now] = true;
            return d[now];
        };

        ll ans = 0;
        rep(i, v) {
            ll tmp = dfs(dfs, i);
            if (tmp == -1) {
                return -1;
            }
            ans = max(tmp, ans);
        }
        return ans;
    }
};

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll v, e;
        cin >> v >> e;
        DAG dag(v, e);
        rep(i, e) {
            ll s = inl(), t = inl();
            dag.add(s, t);
        }
        vl ans = dag.sort();
        each(m, ans) cout << m << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}