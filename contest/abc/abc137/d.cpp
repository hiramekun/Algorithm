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

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        ll n, m;
        cin >> n >> m;

        pq<pair<ll, ll>> que;
        rep(i, n) {
            ll a, b;
            cin >> a >> b;
            if (a > m) continue;
            que.push(make_pair(-a, b));
        }

        ll ans = 0;

        pq<pair<ll, ll>> candidates;
        for (ll i = 0; i <= m; ++i) {
            while (!que.empty() && -que.top().first <= i) {
                P now = que.top();
                candidates.push(make_pair(now.second, now.first));
                que.pop();
            }

            if (!candidates.empty()) {
                ans += candidates.top().first;
                candidates.pop();
            }
        }

        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}