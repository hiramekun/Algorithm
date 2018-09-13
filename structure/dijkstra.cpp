#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)

const int INF = 1000000000;
using namespace std;
const int MAX_V = 10000;
int cost[MAX_V][MAX_V]; // cost[i][j]: i->jのコスト. 辺がない場合はINFにする.
int d[MAX_V];           // d[i]: iへの最短距離.
bool used[MAX_V];       // used[i]: iがすでに使われたかどうか.
int V;                  // 頂点の数.

// 始点sから各頂点への最短距離を求める．
void dijkstra(int s) {
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0; // 始点は0

    while (true) {
        int v = -1;
        // 使われてないかつ短い距離のものがあればそれを採用.
        REP(i, V) if (!used[i] && (v == -1 || d[i] < d[v])) v = i;
        if (v == -1) break;
        used[v] = true;
        // iへの距離は，d[i]と，最短距離のd[v]とv->iの合計の小さいほう．
        REP(i, V) d[i] = min(d[i], d[v] + cost[v][i]);
    }
}

int main() {
    return 0;
}
