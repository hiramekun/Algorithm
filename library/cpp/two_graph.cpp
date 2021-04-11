#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int MAX_V = 1000, W = 0, B = 1;
vector<int> G[MAX_V];
int V;
int color[MAX_V];

bool dfs(int v, int c) {
    color[v] = c; // 頂点vをcで塗る
    for (int g : G[v]) {
        if (color[g] == c) return false;
        if (color[g] == W && !dfs(g, -c)) return false;
    }
    return true;
}

void solve() {
    for (int i = 0; i < V; ++i) {
        if (color[i] == W) {
            if (!dfs(i, B)) {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main() {
    int E;
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        G[t].push_back(s);
    }
    solve();
    return 0;
}
