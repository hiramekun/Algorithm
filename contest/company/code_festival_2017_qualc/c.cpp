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
    int n = s.length();
    string rev;
    int i_s = inf, i_e = -1;
    rep(i, n) {
        if (s[i] != 'x') {
            i_s = min(i_s, i), i_e = max(i_e, i);
            rev += s[i];
        }
    }
    if (i_s == inf) i_s = -1;
    rep(i, rev.length() / 2) {
        if (rev[i] != rev[rev.length() - 1 - i]) {
            cout << "-1" << endl;
            return;
        }
    }
    if (i_s == -1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < i_s; ++i) if (s[i] == 'x') ans++;
    for (int i = i_e; i < n; ++i) if (s[i] == 'x') ans--;
    ans = abs(ans);


    while (i_s < i_e) {
        if (s[i_s] == s[i_e]) i_s++, i_e--;
        else if (s[i_s] == 'x') {
            i_s++;
            ans++;
        } else if (s[i_e] == 'x') {
            i_e--;
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}
