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

const int MAX_N = 8, MAX_M = 8 * 7 / 2;
bool G[MAX_N][MAX_N];
int N, M;

int dfs(int v, bool visited[]) {
    bool all_visited = true;
    REP(i, N) if (!visited[i]) all_visited = false;
    if (all_visited) return 1;

    int ret = 0;
    REP(i, N) {
        if (!G[v][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        ret += dfs(i, visited);
        visited[i] = false;
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a][b] = G[b][a] = true;
    }
    bool visited[MAX_N];
    fill(visited, visited + N, false);
    visited[0] = true;
    cout << dfs(0,visited) << endl;
    return 0;
}
