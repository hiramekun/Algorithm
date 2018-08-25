#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

const int INF = 1000000000;
using namespace std;
const int MAX_V = 10000;
int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

// 始点sから各頂点への最短距離を求める．
void dijkstra(int s) {
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;

    while (true) {
        int v = -1;
        for (int i = 0; i < V; ++i) {
            if (!used[i] && (v == -1 || d[i] < d[v])) v = i;
        }
        if (v == -1) break;
        used[v] = true;

        for (int j = 0; j < V; ++j) {
            d[j] = min(d[j], d[v] + cost[v][j]);
        }
    }
}

int main() {
    return 0;
}
