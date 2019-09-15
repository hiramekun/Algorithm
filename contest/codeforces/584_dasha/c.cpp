/**
 * Created by hiramekun at 21:53 on 2019-09-14.
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
using data = pair<ll, P>; // first -> 数字 , second.first -> 添字

void solve() {
    ll t;
    cin >> t;
    rep(_, t) {
        ll n;
        cin >> n;
        string d;
        cin >> d;

        unordered_map<ll, ll> mp;
        unordered_map<ll, set<ll>> idx;
        rep(i, n) {
            mp[d[i] - '0']++;
            idx[d[i] - '0'].insert(i);
        }

        minpq<P> pq(all(mp)); // first -> 数字, second -> 個数
        vector<char> ans(n);
        rep(j, 2) {
            ll now = 0;
            while (!pq.empty()) {
                P numC = pq.top();
                ll num = numC.first, cnt = numC.second;
                pq.pop();

                auto itr = idx[num].lower_bound(now);
                if (itr == idx[num].end()) {
                    pq.push(numC);
                    break;
                }
                ll i = *itr;

                cnt--;
                if (cnt > 0) pq.push(P(num, cnt));

                now = i;
                idx[num].erase(i);
                ans[i] = j + '1';
            }
        }
        if (pq.empty()) cout << string(all(ans)) << '\n';
        else cout << "-" << '\n';
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
