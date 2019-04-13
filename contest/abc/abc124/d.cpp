#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <numeric>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef unordered_map<string, ll> mpsl;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n = inl(), k = inl();
        string s = ins();

        vector<pair<ll, ll>> zeros;
        rep(i, s.size()) {
            if (s[i] == '0') {
                ll l, r;
                l = i;
                while (i < s.size() - 1 && s[i] == '0' && s[i] == s[i + 1]) i++;
                r = i;
                zeros.eb(P(l, r));
            }
        }
        ll d[n];
        rep(i, s.size()) {
            if (s[i] == '0') d[i] = 0;
            else d[i] = (i == 0 ? 1 : d[i - 1] + 1);
        }
        ll dd[n];
        repr(i, n) {
            if (d[i] == 0) dd[i] = 0;
            else if (i == n - 1) dd[i] = d[i];
            else dd[i] = max(dd[i + 1], d[i]);
        }

        ll ans = 0;
        k = min<ll>(zeros.size(), k);
        if (k == 0) {
            cout << n << endl;
        } else {
            rep(i, zeros.size() - k + 1) {
                ll s = zeros[i].F, t = zeros[i + k - 1].S;
                ans = max((s == 0 ? 0 : dd[s - 1]) + t - s + 1 +
                          (t == n - 1 ? 0 : dd[t + 1]), ans);
            }
            cout << ans << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}