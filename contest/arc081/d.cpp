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
    int first = 0;
    bool is_pre_stands = false;

    if (s1[0] == s2[0]) {
        is_pre_stands = true;
        first = 1;
        ans *= 3;
    } else {
        first = 2;
        ans *= 6;
    }

    FOR(i, first, n) {
        if (s1[i] == s2[i]) {
            if (is_pre_stands) ans *= 2;
            is_pre_stands = true;

        } else {
            if (is_pre_stands) ans *= 2;
            else ans *= 3;
            i++;
            is_pre_stands = false;
        }
        ans %= mod;
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    cin >> s1 >> s2;
    solve();
    return 0;
}
