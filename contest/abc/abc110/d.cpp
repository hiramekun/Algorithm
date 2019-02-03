#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
const ll mod = 1000000007;

ll n, m;

// 素因数分解
unordered_map<ll, ll> prime_factor(ll n) {
    unordered_map<ll, ll> mp;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1) mp[n]++;
    return mp;
}

typedef long long ll;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll COM(ll n, ll k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

void solve() {
    unordered_map<ll, ll> mp = prime_factor(m);
    ll ans = 1;
    COMinit();
    each(m, mp) {
        ans *= COM(n - 1 + m.second, m.second);
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m;
    solve();
    return 0;
}
