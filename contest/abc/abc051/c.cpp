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
    int dx = tx - sx;
    int dy = ty - sy;
    cout << string(dx, 'R') << string(dy, 'U') << string(dx, 'L') << string(dy, 'D');
    putchar('L');
    cout << string(dy + 1, 'U') << string(dx + 1, 'R');
    putchar('D');
    putchar('R');
    cout << string(dy + 1, 'D') << string(dx + 1, 'L');
    putchar('U');
}

int main() {
    cin >> sx >> sy >> tx >> ty;
    solve();
    return 0;
}
