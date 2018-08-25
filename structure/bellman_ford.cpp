#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int INF = 1000000000;
const int MAX_V = 100, MAX_E = 100;

struct edge {
    int from, to, cost;
};

edge es[MAX_E];
int d[MAX_V];
int V, E; // Vは頂点数，Eは辺数

// s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s) {
    for (int i = 0; i < V; ++i) d[i] = INF;
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; ++i) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

int main() {
    cin >> V >> E;
    int s;
    cin >> s;
    shortest_path(s);
    return 0;
}
