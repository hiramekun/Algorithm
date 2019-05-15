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

// 素因数分解

map<ll, ll> mp;

void prime_factor(ll n) {
    unordered_map<ll, ll> tmp;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            tmp[i]++;
            n /= i;
        }
    }
    if (n != 1) tmp[n]++;
    each(m, tmp) if (m.second > mp[m.first]) mp[m.first] = m.second;
}

// 素数判定
bool is_prime(ll n) {
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return n != 1;
}

// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll t = inl();
        rep(_, t) {
            ll n = inl();
            vl d(n);
            ll l = 1;
            mp = map<ll, ll>();

            rep(i, n) {
                scanf("%lli", &d[i]);
                l = lcm(d[i], l);
                prime_factor(d[i]);
            }
            sort(all(d));
            ll tmp = 1;
            if (d.back() == l) mp[d[0]]++, l *= d[0];

            each(m, mp) {
                tmp *= (m.second + 1);
            }
            if (tmp - 2 == n) {
                printf("%lli\n", l);
            } else {
                printf("-1\n");
            }
        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}