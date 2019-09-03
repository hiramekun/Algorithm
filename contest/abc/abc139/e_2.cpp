/**
 * Created by hiramekun at 15:11 on 2019-09-02.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vl = vector<ll>;
using vvl = vector<vl>;
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
    ll n;
    cin >> n;

    vector<queue<ll>> v(n);
    rep(i, n) {
        rep(j, n - 1) {
            ll a;
            cin >> a;
            v[i].push(--a);
        }
    }

    queue<ll> next;
    ll res = n * (n - 1);
    ll ans = 0;
    bool flag = false;
    vb seen(n);

    auto solve = [&](ll now, queue<ll> &que, vb &seen, bool &flag) {
        if (v[now].empty()) return;
        ll j = v[now].front();
        if (v[j].empty()) return;

        if (!seen[j] && !seen[now] && v[j].front() == now) {
            seen[now] = seen[j] = true;
            v[now].pop(), v[j].pop();
            que.push(now), que.push(j);
            res -= 2;
            flag = true;
        }
    };
    auto validate_and_cnt = [&](bool flag) {
        if (flag) ans++;
        else {
            cout << -1 << '\n';
            exit(0);
        }
    };

    // initialize
    rep(i, n) {
        solve(i, next, seen, flag);
    }
    validate_and_cnt(flag);

    while (res > 0) {
        flag = false;
        fill(all(seen), false);
        queue<ll> tmp;
        while (!next.empty()) {
            ll now = next.front();
            next.pop();
            solve(now, tmp, seen, flag);
        }
        validate_and_cnt(flag);
        next = tmp;
    }

    cout << ans << '\n';
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


