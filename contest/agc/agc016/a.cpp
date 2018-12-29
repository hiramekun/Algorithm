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
#define reprone(i, n) for(ll i = n; i >= 1; i--)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

string s;

bool all_same(string s, char target) {
    rep(i, s.length()) if (s[i] != target) return false;
    return true;
}

void solve() {
    int ans = i_inf;
    for (int i = 'a'; i <= 'z'; ++i) {
        string s1(s);
        int temp = 0;
        while (s1.length() != 0 && !all_same(s1, char(i))) {
            reprone(j, s1.length() - 1) {
                if (s1[j] == char(i) && s1[j - 1] != char(i)) {
                    s1[j - 1] = char(i);
                    j--;
                    if (j == 0) break;
                }
            }
            temp++;
            s1.erase(s1.end() - 1);
        }
        if (all_same(s1, char(i))) ans = min(ans, temp);
    }
    cout << ans << endl;
}

int main() {
    cin >> s;
    solve();
    return 0;
}
