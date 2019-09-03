/**
 * Created by hiramekun at 15:21 on 2019-09-03.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
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
    DAG(ll v) : v(v) {
        table.resize(v);
        in_d.resize(v);
        e = 0;
    }

    void add(ll from, ll to) {
        table[from].eb(to);
        in_d[to]++;
        e++;
    }

    // O(v + e)
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    vl sort() {
        stack<ll> st; // 入力次数が0の頂点集合

        rep(i, v) if (in_d[i] == 0) {
                st.push(i);
            }
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


void solve() {
    ll n;
    cin >> n;
    vvl ptov(n, vl(n));
    vvl a(n, vl(n - 1));
    rep(i, n) {
        rep(j, n - 1) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    ll tmp = 0;
    rep(i, n - 1) {
        for (ll j = i + 1; j < n; ++j) {
            ptov[i][j] = tmp++;
        }
    }
    auto to_id = [&](ll i, ll j) -> ll {
        auto ij = minmax(i, j);
        return ptov[ij.F][ij.S];
    };
    DAG dag(tmp);
    rep(i, n) {
        rep(j, n - 1) {
            a[i][j] = to_id(i, a[i][j]);
        }
    }
    rep(i, n) {
        rep(j, n - 2) {
            dag.add(a[i][j], a[i][j + 1]);
        }
    }
    ll ans = dag.get_longest_path();
    cout << ans << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}
