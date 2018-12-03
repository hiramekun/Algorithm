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
struct edge {
    ll to, cost;
};
ll N, M;
const int MAX_N = int(1e5);
ll L[2 * MAX_N], R[2 * MAX_N], D[2 * MAX_N];
vector<edge> G[MAX_N];

bool dfs(ll start, ll to, ll dest, ll costs) {
    if (start == to) return false;

    if (to == dest) {
        REP(i, G[start].size()) {
            edge g = G[start][i];
            if (dest == g.to) return g.cost == costs;
        }
        return true;
    }
    REP(i, G[to].size()) {
        edge g = G[to][i];
        if (!dfs(start, g.to, dest, costs + g.cost)) return false;
    }
    return true;
}

void solve() {
    REP(i, M) {
        REP(j, G[L[i]].size()) {
            edge g = G[L[i]][j];
            if (g.to != R[i] && !dfs(L[i], g.to, R[i], g.cost)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin >> N >> M;
    REP(i, M) {
        cin >> L[i] >> R[i] >> D[i];
        L[i]--, R[i]--;
        edge e = {R[i], D[i]};
        G[L[i]].emplace_back(e);
    }
    solve();
    return 0;
}
