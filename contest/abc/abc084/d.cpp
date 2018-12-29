#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);


// n以下の素数を返す
vector<bool> sieve(ll n) {
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
    return is_prime;
}


ll q;
vector<ll> l, r;
vector<ll> prime_count(half_inf + 1, 0);

void solve() {
    vector<bool> is_prime = sieve(half_inf);
    repone(i, half_inf) {
        if (is_prime[i] && is_prime[(i + 1) / 2]) prime_count[i] = prime_count[i - 1] + 1;
        else prime_count[i] = prime_count[i - 1];
    }
    rep(i, q) {
        cout << prime_count[r[i]] - prime_count[l[i] - 1] << endl;
    }
}

int main() {
    cin >> q;
    l.resize(q), r.resize(q);
    rep(i, q) cin >> l[i] >> r[i];
    solve();
    return 0;
}
