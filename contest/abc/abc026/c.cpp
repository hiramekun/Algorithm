#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>

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

template<class T, class K>
T cast(K v) {
    return boost::lexical_cast<T>(v);
}

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
        ll n;
        cin >> n;
        vl b(n + 1);
        rep(i, n - 1) {
            cin >> b[i + 2];
        }

        vl mi(n + 1), ma(n + 1), val(n + 1);
        for (ll i = n; i >= 2; --i) {
            val[i] = mi[i] + ma[i] + 1;
            mi[b[i]] = mi[b[i]] == 0 ? val[i] : min(mi[b[i]], val[i]);
            ma[b[i]] = max(ma[b[i]], val[i]);
        }
        cout << mi[1] + ma[1] + 1 << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}