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

ll d[26][half_inf + 1];
int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll t = inl();
        rep(tc, t) {
            ll n = inl(), q = inl();
            string s = ins();
            vector<P> lr(q);
            rep(i, q) {
                ll l = inl(), r = inl();
                l--, r--;
                lr[i] = P(l, r);
            }

            rep(i, 26) d[i][0] = 0;
            rep(i, n) {
                rep(j, 26) d[j][i + 1] = d[j][i];
                d[s[i] - 'A'][i + 1]++;
            }

            ll ans = 0;
            rep(i, q) {
                ll ce = 0, co = 0;
                ll l = lr[i].first, r = lr[i].second;
                rep(j, 26) {
                    ll tmp = d[j][r + 1] - d[j][l];
                    if (tmp) {
                        if (tmp % 2 == 0) ce++;
                        else co++;
                    }
                }
                if (co <= 1) ans++;
            }
            cout << "Case #" << tc + 1 << ": " << ans << endl;
        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}