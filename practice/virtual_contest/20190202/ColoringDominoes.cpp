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

int n;
string s1, s2;

void solve() {
    ll ans = 1;
    rep(i, n) {
        if (i == 0) {
            if (s1[i] == s2[i]) ans *= 3;
            else ans *= 6, i++;
        } else {
            if (s1[i] == s2[i]) {
                if (s1[i - 1] == s2[i - 1]) ans *= 2;
                else ans *= 1;
            } else if (s1[i] != s2[i]) {
                if (s1[i - 1] == s2[i - 1]) ans *= 2;
                else ans *= 3;
                i++;
            }
        }
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> s1 >> s2;
    solve();
    return 0;
}
