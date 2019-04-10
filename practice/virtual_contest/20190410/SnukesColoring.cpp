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
        ll h = inl(), w = inl(), n = inl();
        vl a(n), b(n);
        vector<P> ab(n);
        map<P, ll> mp, seen;
        rep(i, n) {
            a[i] = inl(), b[i] = inl();
            a[i]--, b[i]--;
            ab[i] = P(a[i], b[i]);
            mp[ab[i]]++;
        }
        vl ans(10);
        each(m, ab) {
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    ll ni = m.first + i, nj = m.second + j;
                    if (ni < 1 || ni > h - 2 || nj < 1 || nj > w - 2) continue;
                    if (seen[P(ni, nj)] > 0) continue;
                    ll c = 0;
                    for (int k = -1; k <= 1; ++k) {
                        for (int l = -1; l <= 1; ++l) {
                            if (mp[P(ni + k, nj + l)] > 0) c++;
                        }
                    }
                    ans[c]++, seen[P(ni, nj)]++;
                }
            }
        }
        ans[0] = (h - 3 + 1) * (w - 3 + 1) - accumulate(all(ans), 0LL);
        rep(i, 10) cout << ans[i] << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}