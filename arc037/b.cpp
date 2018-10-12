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

using namespace std;
const int MAX_V = 100;
vector<int> G[MAX_V + 1];
bool seen[MAX_V + 1];
int N, M;

bool dfs(int i, int before) {
    seen[i] = true;
    EACH(g, G[i]) {
        if (seen[g] && g != before) return false;
        else if (g != before) if (!dfs(g, i)) return false;
    }
    return true;
}

void solve() {
    int ans = 0;
    REPONE(i, N) {
        if (seen[i]) continue;
        if (dfs(i, -1)) ans++;
    }
    cout << ans << endl;
}

int main() {
    scanf("%d %d", &N, &M);
    REP (i, M) {
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
    solve();
    return 0;
}
