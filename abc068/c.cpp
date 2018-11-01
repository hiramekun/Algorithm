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

ll N, M;
const int MAX_M = (int) 1e5 * 2;
vector<ll> G[MAX_M];

void solve() {
    REP(i, G[0].size()) {
        REP(j, G[G[0][i]].size()) {
            if (G[G[0][i]][j] == N - 1) {
                cout << "POSSIBLE" << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        G[a - 1].emplace_back(b - 1);
    }
    solve();
    return 0;
}
