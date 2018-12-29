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
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int W = 10, H = 10;
char A[H][W];
bool seen[H][W];
int g_count, t_count;

bool dfs(int i, int j) {
    if (i < 0 || j < 0 || i > H - 1 || j > W - 1 || seen[i][j] || A[i][j] == 'x') return false;
    seen[i][j] = true;
    t_count++;
    if (t_count == g_count + 1) return true;
    if (dfs(i + 1, j)) return true;
    if (dfs(i - 1, j)) return true;
    if (dfs(i, j + 1)) return true;
    if (dfs(i, j - 1)) return true;
    return false;
}

void solve() {
    REP(i, H) REP(j, W) {
            fill(seen[0], seen[0] + H * W, false);
            t_count = 0;
            char temp = A[i][j];
            A[i][j] = 'o';
            if (dfs(i, j)) {
                cout << "YES" << endl;
                return;
            }
            A[i][j] = temp;
        }
    cout << "NO" << endl;
}

int main() {
    REP(i, H) REP(j, W) {
            cin >> A[i][j];
            if (A[i][j] == 'o') g_count++;
        }
    solve();
    return 0;
}
