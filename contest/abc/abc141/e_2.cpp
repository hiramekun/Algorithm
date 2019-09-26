/**
 * Created by hiramekun at 15:09 on 2019-09-26.
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
vl calculate_z(const string &input) {
    ll n = input.size();
    vl z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; ++i) {
        if (i > r) {
            l = r = i;
            while (r < n && input[r] == input[r - l]) r++;
            z[i] = r - l;
            r--;
        } else {
            ll i1 = i - l;
            if (z[i1] < r - i + 1) {
                z[i] = z[i1];
            } else {
                l = i;
                while (r < n && input[r] == input[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

vl calc_match(const string &a, const string &pattern) {
    string s = pattern + "$" + a;
    vl z = calculate_z(s);
    vl ret;
    for (ll i = pattern.size() + 1; i < z.size(); ++i) {
        ret.eb(z[i]);
    }
    return ret;
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans  = 0;
    rep(i, n) {
        string pattern = s.substr(i, n - i);
        string a = s.substr(0, i);
        if (pattern.empty() || a.empty()) continue;
        vl tmp = calc_match(a, pattern);
        ans = max(ans, *max_element(all(tmp)));
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
