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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll m, ll n) {
    if ((0 == m) || (0 == n)) return 0;
    return ((m / gcd(m, n)) * n);
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n = inl(), m = inl();
        vl x(n), p(m);
        rep(i, n) cin >> x[i];
        rep(i, m) cin >> p[i];

        ll y = x[0];

        ll diff[n - 1];
        ll temp = -1;
        for (int i = 0; i < n - 1; ++i) {
            diff[i] = x[i + 1] - x[i];
            if (temp == -1) temp = diff[i];
            else temp = gcd(temp, diff[i]);
        }

        for (int i = 0; i < m; ++i) {
            if (temp % p[i] == 0) {
                cout << "YES" << endl;
                cout << y << " " << i + 1 << endl;
                return 0;
            }
        }
        cout << "NO" << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}