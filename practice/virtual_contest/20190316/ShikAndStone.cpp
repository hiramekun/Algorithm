#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <numeric>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;
bool seen[8][8];
char a[8][8];
int h, w;

bool dfs(ll i, ll j, ll ti, ll tj) {
    seen[i][j] = true;
    if (i == ti && j == tj) return true;
    if (i + 1 <= h - 1 && !seen[i + 1][j] && a[i + 1][j] == '#') return dfs(i + 1, j, ti, tj);
    if (j + 1 <= w - 1 && !seen[i][j + 1] && a[i][j + 1] == '#') return dfs(i, j + 1, ti, tj);
    return false;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        cin >> h >> w;
        rep(i, h) rep(j, w) cin >> a[i][j];

        if (dfs(0, 0, h - 1, w - 1)) {
            rep(i, h) {
                rep(j, w) {
                    if (a[i][j] == '#' && !seen[i][j]) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            }
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}