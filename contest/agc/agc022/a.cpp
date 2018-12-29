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
unordered_map<char, int> mp;

void solve() {
    if (s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return;
    }
    rep(i, s.length()) mp[s[i]] = int(i + 1);
    for (char i = 'a'; i <= 'z'; i++) {
        if (mp[i] == 0) {
            cout << s + i << endl;
            return;
        }
    }
    string min_s = "zz";
    rep(i, s.length()) {
        string cs(s);
        string temp1 = cs.substr(0, i + 1), temp2 = cs.substr(0, i + 1);
        unordered_map<char, int> mp1, mp2;
        rep(j, temp1.length()) mp1[temp1[j]]++;
        rep(j, temp2.length()) mp2[temp2[j]]++;
        for (char j = temp1[i]; j <= 'z'; j++) {
            if (mp1[j] == 0) {
                temp1[i] = j;
                min_s = min(min_s, temp1);
                break;
            }
        }
        if (i != 0)
            for (char j = temp2[i - 1]; j <= 'z'; j++) {
                if (mp2[j] == 0) {
                    temp2[i - 1] = j;
                    min_s = min(min_s, temp2);
                    break;
                }
            }
    }
    cout << min_s << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}