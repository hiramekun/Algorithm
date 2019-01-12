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

ll h, w;
char s[400][400];
ll ans;
bool searched[400][400];
bool goal[400][400];

void dfs(int i, int j, char start, ll bc, ll wc) {
    searched[i][j] = true;
    bool has_next = false;
    goal[i][j] = true;
    if (s[i][j] == '#') {
        if (i + 1 <= h - 1 && s[i + 1][j] == '.' && !goal[i + 1][j]) {
            has_next = true;
            dfs(i + 1, j, start, bc, wc + 1);
        }

        if (j + 1 <= w - 1 && s[i][j + 1] == '.' && !goal[i][j + 1]) {
            has_next = true;
            dfs(i, j + 1, start, bc, wc + 1);
        }

    } else {
        if (i + 1 <= h - 1 && s[i + 1][j] == '#' && !goal[i + 1][j]) {
            has_next = true;
            dfs(i + 1, j, start, bc + 1, wc);
        }

        if (j + 1 <= w - 1 && s[i][j + 1] == '#' && !goal[i][j + 1]) {
            has_next = true;
            dfs(i, j + 1, start, bc + 1, wc);
        }
    };

    if (!has_next) {
        if (s[i][j] == start && bc > 0 && wc > 0) {
            repone(c, min(bc, wc)) ans += (c * 2);
        } else if (s[i][j] != start) {
            repone(c, bc) ans += c;
        }
    }
}

void solve() {
    fill(searched[0], searched[400], false);
    rep(i, h) {
        rep(j, w) {
            if (!searched[i][j] && s[i][j] == '#') {
                fill(goal[0], goal[400], false);
                dfs(i, j, '#', 1, 0);
            }
            if (!searched[i][j] && s[i][j] == '.') {
                fill(goal[0], goal[400], false);
                dfs(i, j, '.', 0, 1);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> h >> w;
    rep(i, h) {
        string temp;
        cin >> temp;
        rep(j, w) s[i][j] = temp[j];
    }
    solve();
    return 0;
}
