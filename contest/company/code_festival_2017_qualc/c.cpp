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
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

string s;

void solve() {
    ll ans = 0;
    int i_s = 0, i_e = s.length() - 1;
    while (i_s < i_e) {
        if (s[i_s] == s[i_e]) i_s++, i_e--;
        else if (s[i_s] == 'x') {
            i_s++;
            ans++;
        } else if (s[i_e] == 'x') {
            i_e--;
            ans++;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}
