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
        ll a, b, c;
        cin >> a >> b >> c;

        ll week = min({a / 3, b / 2, c / 2});
        a -= 3 * week, b -= 2 * week, c -= 2 * week;
        vl abc = {a, b, c};
        ll ans = 0;
        const int A = 0, B = 1, C = 2;
        ll weeks[7] = {A, B, C, A, C, B, A};
        rep(i, 7) {
            ll tmp = 0;
            vl cop(abc);
            rep(j, 7) {
                ll idx = i + j;
                if (idx >= 7) idx = idx - 7;
                if (cop[weeks[idx]]--) tmp++;
                else break;
            }
            ans = max(ans, week * 7 + tmp);
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}