/**
 * Created by hiramekun at 15:13 on 2019-08-23.
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
    ll n;
    cin >> n;
    vl x(n), y(n), h(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> h[i];
    }

    for (ll Cx = 0; Cx <= 100; ++Cx) {
        for (ll Cy = 0; Cy <= 100; ++Cy) {
            ll H = -1;
            rep(i, n) {
                if (h[i] != 0) {
                    ll dx = abs(x[i] - Cx), dy = abs(y[i] - Cy);

                    ll tmp = h[i] + dx + dy;
                    if (H == -1) H = tmp;
                    if (H != tmp) break;
                }

                if (i == n - 1) {
                    rep(j, n) {
                        ll dx = abs(x[j] - Cx), dy = abs(y[j] - Cy);
                        if (h[j] == 0 && dx + dy < H) break;
                        if (j == n - 1) {
                            cout << Cx << " " << Cy << " " << H << '\n';
                        }
                    }
                }
            }
        }
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
