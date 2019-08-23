/**
 * Created by hiramekun at 14:24 on 2019-08-21.
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
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

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {
    ll MAX_V = 100;
    vector<ll> G[MAX_V];
    vector<bool> seen(MAX_V);
    auto dfs = [&](auto &&f, ll now) -> void {
        seen[now] = true;
        each(e, G[now]) {
            if (!seen[e]) {
                f(f, e);
            }
        }
    };

    ll n, g, e;
    cin >> n >> g >> e;
    vl p(g);
    cin >> p;
    p.pop_back();
    rep(i, e) {
        ll a, b;
        G[a].eb(b);
        G[b].eb(a);
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
