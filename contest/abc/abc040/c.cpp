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

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        ll n = inl();
        vl a(n);
        rep(i, n) cin >> a[i];

        vl dp(n);
        dp[1] = dp[0] + abs(a[1] - a[0]);
        for (long long i = 2; i < n; ++i) {
            dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
        }
        cout << dp[n - 1] << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}
