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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll n;

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

void solve() {
    vector<ll> v = divisor(n);
    ll ans = ll_inf;
    each(m, v) {
        ans = min(ans, max(ll(to_string(n / m).size()), ll(to_string(m).size())));
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    solve();
    return 0;
}
