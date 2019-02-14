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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

int main() {
    int h, w;
    cin >> h >> w;
    char s[h][w];
    rep(i, h)rep(j, w) cin >> s[i][j];

    char ans[h][w];
    rep(i, h)
        rep(j, w) {
            if (s[i][j] == '#') {
                ans[i][j] = '#';
                continue;
            }
            int c = 0;
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    int nx = i + k, ny = j + l;
                    if (nx >= 0 && nx <= h - 1 && ny >= 0 && ny <= w - 1) {
                        if (s[nx][ny] == '#') c++;
                    }
                }
            }
            ans[i][j] = static_cast<char>(c + '0');
        }
    rep(i, h) {
        rep(j, w) cout << ans[i][j];
        printf("\n");
    }
    return 0;
}
