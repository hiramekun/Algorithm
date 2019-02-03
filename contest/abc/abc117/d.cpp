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
#include <bitset>

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


ll n, k;
vector<ll> a;

void solve() {
    ll bits[48];
    fill(bits, bits + 48, 0);

    rep(i, n) {
        bitset<48> bitset1(a[i]);
        int idx = 0;
        while (bitset1.to_ullong() > 0) {
            bits[idx] += (bitset1.to_ullong() & 1);
            bitset1 = (bitset1 >> 1);

            idx++;
        }
    }

    ll ans = 0;
    repr(i, 48) {
        if (bits[i] <= n / 2) {
            ll temp = ll(pow(2, i));
            if (ans + temp <= k) ans += temp;
        }
    }
    ll ans_f = 0;
    rep(i, n) {
        ans_f += ans^a[i];
    }
    cout << ans_f << endl;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
    solve();
    return 0;
}
