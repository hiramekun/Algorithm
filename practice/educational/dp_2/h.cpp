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

ll h, w;
char a[1000][1000];
ll d[1000][1000];


void bfs(P s) {
    queue<P> que;
    que.push(s);
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        if (p.first + 1 < h && a[p.first + 1][p.second] == '.') {
            if (d[p.first + 1][p.second] == 0) que.push(P(p.first + 1, p.second));
            d[p.first + 1][p.second] += d[p.first][p.second];
            d[p.first + 1][p.second] %= mod;
        }
        if (p.second + 1 < w && a[p.first][p.second + 1] == '.') {
            if (d[p.first][p.second + 1] == 0) que.push(P(p.first, p.second + 1));
            d[p.first][p.second + 1] += d[p.first][p.second];
            d[p.first][p.second + 1] %= mod;
        }
    }
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
        rep(i, h)rep(j, w) cin >> a[i][j];
        rep(i, h)rep(j, w) d[i][j] = 0;
        d[0][0] = 1;
        bfs(P(0, 0));
        cout << d[h - 1][w - 1] << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}