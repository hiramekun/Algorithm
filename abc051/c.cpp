#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int sx, sy, tx, ty;

void solve() {
    if (tx > sx) {
        REP(i, tx - sx) putchar('R');
        if (ty > sy) {
            REP(i, ty - sy) putchar('U');
            REP(i, tx - sx) putchar('L');
            REP(i, ty - sy)putchar('D');
            putchar('L');
            REP(i, ty - sy + 1) putchar('U');
            REP(i, tx - sx + 1) putchar('R');
            putchar('D');
            putchar('R');
            REP(i, ty - sy + 1) putchar('D');
            REP(i, tx - sx + 1) putchar('L');
            putchar('U');
        } else {
            REP(i, sy - ty) putchar('D');
            REP(i, tx - sx) putchar('L');
            REP(i, sy - ty)putchar('U');
            putchar('L');
            REP(i, sy - ty + 1) putchar('D');
            REP(i, tx - sx + 1) putchar('R');
            putchar('U');
            putchar('R');
            REP(i, sy - ty + 1) putchar('U');
            REP(i, tx - sx + 1) putchar('L');
            putchar('D');
        }
    } else {
        REP(i, sx - tx) putchar('L');
        if (ty > sy) {
            REP(i, ty - sy) putchar('U');
            REP(i, sx - tx) putchar('R');
            REP(i, ty - sy)putchar('D');
            putchar('R');
            REP(i, ty - sy + 1) putchar('U');
            REP(i, sx - tx + 1) putchar('L');
            putchar('D');
            putchar('L');
            REP(i, ty - sy + 1) putchar('D');
            REP(i, sx - tx + 1) putchar('R');
            putchar('U');
        } else {
            REP(i, sy - ty) putchar('D');
            REP(i, sx - tx) putchar('R');
            REP(i, sy - ty)putchar('U');
            putchar('R');
            REP(i, sy - ty + 1) putchar('D');
            REP(i, sx - tx + 1) putchar('L');
            putchar('U');
            putchar('L');
            REP(i, sy - ty + 1) putchar('U');
            REP(i, sx - tx + 1) putchar('R');
            putchar('D');
        }
    }
}

int main() {
    cin >> sx >> sy >> tx >> ty;
    solve();
    return 0;
}
