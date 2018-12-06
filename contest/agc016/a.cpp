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

string s;
unordered_map<char, vector<int> > mp;

void solve() {
    int ans = i_inf;
    rep(i, s.length()) mp[s[i]].emplace_back(i);
    each(m, mp) {
        int pre = -1, d_max = 0, to_last = i_inf;
        each(i, m.second) {
            int d = pre == -1 ? i : i - pre - 1;
            pre = i;
            d_max = max(d_max, d);
            to_last = min(to_last, int(s.length() - 1 - i));
        }
        ans = min(max(d_max, to_last), ans);
    }
    cout << ans << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}
