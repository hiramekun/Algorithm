#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n - 1; i >= 0; i--)
#define repone(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for (auto i : mp)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

// 素因数分解
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> mp;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1) mp[n]++;
    return mp;
}

// 素数判定
bool is_prime(ll n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n != 1;
}

// 約数列挙
vector<ll> divisor(ll n) {
    vector<ll> res;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}

// n以下の素数を返す
vector<ll> sieve(ll n) {
    vector<ll> prime;
    vector<bool> is_prime;
    is_prime.resize(n + 1);
    prime.resize(n);
    ll p = 0;
    rep(i, n + 1) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    FOR(i, 2, n + 1) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (ll j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return prime;
}
