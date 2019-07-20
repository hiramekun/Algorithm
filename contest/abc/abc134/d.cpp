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

// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        ll n = inl();
        vl a(n);
        rep(i, n) cin >> a[i];

        vl sums(n);
        v<bool> add(n, false);
        for (ll i = n - 1; i >= 1; --i) {
            vl pri = divisor(i + 1);

            if ((a[i] == 1 && sums[i] % 2 != 1) || (a[i] == 0 && sums[i] % 2 == 1)) {
                add[i] = true;
                each(e, pri) {
                    sums[e - 1]++;
                }
            }
        }
        ll ss = 0;
        rep(i, n) ss += add[i];

        ll ans = 0;
        vl ansv;
        if ((a[0] == 1 && ss % 2 == 0) || (a[0] == 0 && ss % 2 != 0)) {
            ans++;
            ansv.eb(1);
        }
        for (ll i = 1; i < n; ++i) {
            if (add[i]) {
                ansv.eb(i + 1);
                ans++;
            }
        }
        cout << ans << endl;
        each(e, ansv) cout << e << " ";

#ifdef MY_DEBUG
    }
#endif
    return 0;
}
