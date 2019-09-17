/**
 * Created by hiramekun at 17:35 on 2019-09-15.
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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    unordered_map<ll, ll> idx;
    rep(i, n) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    vl l(n), r(n);
    rep(i, n) l[i] = i - 1; // 左にない時、-1
    rep(i, n) r[i] = i + 1; // 右にない時、n

    set<ll> s(all(a));
    vl ans(n);
    ll turn = 1;
    while (!s.empty()) {
        ll now = *s.rbegin();
        s.erase(now);
        ll i = idx[now];

        ans[i] = turn;
        ll lIdx = i;
        rep(j, k) {
            if (l[lIdx] == -1) break;
            lIdx = l[lIdx];
            ll left = a[lIdx];
            ans[lIdx] = turn;
            s.erase(left);
        }

        ll rIdx = i;
        rep(j, k) {
            if (r[rIdx] == n) break;
            rIdx = r[rIdx];
            ll right = a[rIdx];
            ans[rIdx] = turn;
            s.erase(right);
        }

        lIdx = l[lIdx], rIdx = r[rIdx];
        if (rIdx != n) l[rIdx] = lIdx;
        if (lIdx != -1) r[lIdx] = rIdx;

        turn = 3 - turn;
    }
    rep(i, n) cout << ans[i];
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
