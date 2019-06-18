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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

string ins() {
    string x;
    cin >> x;
    return (x);
}

/* ----------- ANSWER ----------- */
/* ------------------------------ */

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n, k;
        cin >> n >> k;
        vl a(n);
        rep(i, n) cin >> a[i];
        ll right = 0;

        ll sum = 0;
        ll ans = 0;
        for (ll left = 0; left < n; ++left) {
            while (right < n && sum < k) {
                /* 実際に right を 1 進める */
                sum += a[right];
                ++right;
            }

            /* break した状態で right は条件を満たす最大なので、何かする */
            if (sum >= k) ans += (n - right + 1);

            /* left をインクリメントする準備 */
            if (right == left) ++right;
            else sum -= a[left];
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}