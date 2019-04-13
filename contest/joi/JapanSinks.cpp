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
        ll n = inl();
        vl a;
        map<ll, vector<ll>> b;
        a.eb(0), b[0].eb(0);
        ll idx = 1;
        repone(i, n) {
            ll tmp = inl();
            if (i > 0 && tmp == a.back()) {
                continue;
            }
            a.eb(tmp);
            b[a.back()].eb(idx);
            idx++;
        }
        if (a.back() != 0) a.eb(0), b[0].eb(a.size() - 1);
        ll c = 1, ans = 0;
        each(m, b) {
            each(i, m.S) {
                ll r = a[i + 1 > a.size() - 1 ? i : i + 1];
                ll l = a[i - 1 < 0 ? 0 : i - 1];
                if (a[i] < r && a[i] < l) c++;
                else if (a[i] >= r && a[i] >= l) c--;
            }
            ans = max(c, ans);
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}