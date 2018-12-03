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

int c[3][3];

void solve() {
    int a[3], b[3];
    a[0] = 0, b[0] = c[0][0], b[1] = c[0][1], b[2] = c[0][2];
    a[1] = c[1][0] - b[0], a[2] = c[2][0] - b[0];
    REP(i, 3)REP(j, 3) if (a[i] + b[j] != c[i][j]) {
                cout << "No" << endl;
                return;
            }
    cout << "Yes" << endl;
}

int main() {
    REP(i, 3)REP(j, 3) cin >> c[i][j];
    solve();
    return 0;
}
