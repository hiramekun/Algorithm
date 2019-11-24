/**
 * Created by hiramekun at 20:47 on 2019-11-24.
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
struct edge {
    ll from, to, idx;

    edge() {};

    edge(ll from, ll to, ll idx) : from(from), to(to), idx(idx) {};
};

typedef vector<edge> ve;
typedef vector<ve> vve;


void solve() {
    ll n;
    cin >> n;

    vve g(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].eb(edge(a, b, i));
        g[b].eb(edge(b, a, i));
    }

    vb seen(n);
    vl ans(n - 1);
    auto dfs = [&](auto &&f, ll now, ll col) -> void {
        seen[now] = true;
        ll tmp = col;
        bool plus = false;
        each(e, g[now]) {
            if (seen[e.to]) continue;
            if (plus) tmp++;
            else if (tmp > 1) tmp--;
            else if (tmp <= 1) tmp = col + 1, plus = true;

            ans[e.idx] = tmp;
            f(f, e.to, tmp);
        }
    };
    dfs(dfs, 0, 0);
    cout << *max_element(all(ans)) << '\n';
    rep(i, n - 1) {
        cout << ans[i] << '\n';
    }
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
