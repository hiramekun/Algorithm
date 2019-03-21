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
typedef unordered_map<char, ll> ump;
typedef pair<ll, ll> P;

vector<string> s;
bool seen[400][400];
int h, w;
ll ans = 0;

void bfs(P idx) {
    ump mp;
    mp['#'] = mp['.'] = 0;
    queue<P> que;
    que.push(idx);
    seen[idx.first][idx.second] = true;
    mp[s[idx.first][idx.second]]++;

    while (!que.empty()) {
        P p = que.front();
        que.pop();
        char now = s[p.first][p.second];
        rep(i, 4) {
            ll nx = p.first + dx[i], ny = p.second + dy[i];

            if (0 <= nx && nx < h && 0 <= ny && ny < w && !seen[nx][ny]) {
                if (now != s[nx][ny]) {
                    que.push(P(nx, ny));
                    mp[s[nx][ny]]++;
                    seen[nx][ny] = true;
                }
            }
        }
    }
    ans += mp['#'] * mp['.'];
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        cin >> h >> w;
        s.resize(h);
        rep(i, h) cin >> s[i];
        rep(i, h) rep(j, w) seen[i][j] = false;
        rep(i, h) {
            rep (j, w) if (!seen[i][j]) bfs(P(i, j));
        }
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}
