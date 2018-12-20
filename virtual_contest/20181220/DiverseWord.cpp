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
#define inf int(1e9)
#define half_inf int(1e5)
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
    unordered_map<char, int> mp;
    rep(i, s.length()) mp[s[i]] = i + 1;
    if (s.length() == 26) {
        repr(i, s.length()) {
            for (char j = 'a'; j <= 'z'; ++j) {
                if (j > s[i] && mp[j] > mp[s[i]]) {
                    s[i] = j;
                    cout << s.substr(0, i + 1) << endl;
                    return;
                }
            }
            if (i == 0) cout << "-1" << endl;
        }
    } else {
        for (char j = 'a'; j <= 'z'; ++j) {
            if (mp[j] == 0) {
                cout << s + j << endl;
                return;
            }
        }
    }
}

int main() {
    cin >> s;
    solve();
    return 0;
}
