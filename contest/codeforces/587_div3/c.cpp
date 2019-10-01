/**
 * Created by hiramekun at 15:47 on 2019-09-21.
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

void solve() {
    P xy1, xy2, xy3, xy4, xy5, xy6;
    cin >> xy1.F >> xy1.S >> xy2.F >> xy2.S;
    cin >> xy3.F >> xy3.S >> xy4.F >> xy4.S;
    cin >> xy5.F >> xy5.S >> xy6.F >> xy6.S;

    if (xy3.F <= xy1.F && xy4.F >= xy2.F && xy3.S <= xy1.S && xy4.S >= xy2.S) {
        // 一つ
        cout << "NO" << '\n';
    } else if (xy5.F <= xy1.F && xy6.F >= xy2.F && xy5.S <= xy1.S && xy6.S >= xy2.S) {
        cout << "NO" << '\n';
    } else // 横
    if (xy4.S >= xy2.S && xy3.F <= xy1.F && xy4.F >= xy2.F &&
        xy5.S <= xy1.S && xy5.F <= xy1.F && xy6.F >= xy2.F && xy6.S >= xy3.S) {
        cout << "NO" << '\n';
    } else if (xy3.S <= xy1.S && xy3.F <= xy1.F && xy4.F >= xy2.F &&
               xy6.S >= xy2.S && xy5.F <= xy1.F && xy6.F >= xy2.F && xy4.S >= xy5.S) {
        cout << "NO" << '\n';
    } else // 縦
    if (xy3.F <= xy1.F && xy4.S >= xy2.S && xy3.S <= xy1.S &&
        xy6.F >= xy2.F && xy6.S >= xy2.S && xy5.S <= xy1.S && xy4.F >= xy5.F) {
        cout << "NO" << '\n';
    } else if (xy4.F >= xy2.F && xy4.S >= xy2.S && xy3.S <= xy1.S &&
               xy5.F <= xy1.F && xy6.S >= xy2.S && xy5.S <= xy1.S && xy6.F >= xy3.F) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
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
