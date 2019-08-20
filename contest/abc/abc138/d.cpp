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

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {

    vector<ll> ans(2 * e5);
    unordered_map<ll, ll> pl;
    vector<bool> seen(2 * e5);
    vector<ll> G[2 * e5];

    auto dfs = [&](auto &&f, ll now, ll value) -> void {
        seen[now] = true;
        ans[now] = value;
        each(e, G[now]) {
            if (!seen[e]) {
                f(f, e, value + pl[e]);
            }
        }
    };

    ll n, q;
    cin >> n >> q;
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].eb(b);
        G[b].eb(a);
    }

    rep(i, q) {
        ll p, x;
        cin >> p >> x;
        p--;
        pl[p] += x;
    }
    dfs(dfs, 0, pl[0]);

    rep(i, n) cout << ans[i] << " ";
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