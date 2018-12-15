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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

string s;

void solve() {
    ll ans = i_inf;
    each(c, s) {
        ll temp = 0;
        string scopy(s);
        bool b = false;
        while (!b && !scopy.empty()) {
            rep(j, scopy.length()) {
                if (scopy[j] != c) break;
                if (j == scopy.length() - 1) {
                    b = true;
                }
            }
            if (!b) temp++;
            repone(i, scopy.length() - 1) {
                if (scopy[i] == c) scopy[i - 1] = c;
            }
            scopy.erase(scopy.end() - 1);
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}
