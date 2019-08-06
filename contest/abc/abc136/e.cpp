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

// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return move(res);
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        ll n, k;
        cin >> n >> k;
        vl a(n);
        rep(i, n) cin >> a[i];

        vl divs = divisor(accumulate(all(a), 0LL));

        ll ans = 0;

        each(e, divs) {
            vl mods(n);
            rep(i, n) mods[i] = a[i] % e;
            sort(all(mods));

            vl minuss(n + 1), pluss(n + 1);

            rep(i, n) {
                minuss[i + 1] = minuss[i] + mods[i];
                pluss[i + 1] = pluss[i] + (e - mods[i]);
            }

            for (ll i = 0; i <= n; ++i) {
                ll minus = minuss[i];
                ll plus = pluss[n] - pluss[i];

                if (max(plus, minus) <= k) {
                    ans = max(ans, e);
                }
            }
        }
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}