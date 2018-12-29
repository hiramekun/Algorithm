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
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int N;
ll target = 1;
unordered_map<ll, ll> mp;

// 素数列挙
void prime_factor(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1) mp[n]++;
}

int calc_larger(int n) {
    int ret = 0;
    each(m, mp) {
        if (m.second + 1 >= n) ret++;
    }
    return ret;
}

void solve() {
    ll ans = calc_larger(75) + calc_larger(25) * (calc_larger(3) - 1) +
             calc_larger(15) * (calc_larger(5) - 1) +
             calc_larger(5) * (calc_larger(5) - 1) * (calc_larger(3) - 2) / 2;
    cout << ans << endl;
}

int main() {
    cin >> N;
    repone(i, N) prime_factor(i);

    solve();
    return 0;
}
