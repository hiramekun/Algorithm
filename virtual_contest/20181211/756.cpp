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

map<ll, ll> mp;
ll n;

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

void solve() {
    repone(i, n) prime_factor(i);

    ll three = 0, five = 0, fifteen = 0, twenty_five = 0, seventy_five = 0;
    each(i, mp) {
        if ((i.second + 1) >= 75) seventy_five++;
        if ((i.second + 1) >= 25) twenty_five++;
        if ((i.second + 1) >= 15) fifteen++;
        if ((i.second + 1) >= 5) five++;
        if ((i.second + 1) >= 3) three++;
    }
    cout << seventy_five + twenty_five * (three - 1) + fifteen * (five - 1) +
            five * (five - 1) / 2 * (three - 2) << endl;
}

int main() {
    cin >> n;
    solve();
    return 0;
}
