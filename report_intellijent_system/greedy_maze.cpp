#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;

const int MAX_V = 10000;

struct edge {
    int to, cost;
};
typedef pair<int, int> P; // first: 最短距離, second: 頂点の番号

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
bool seen[MAX_V];

void greedy(int s, int g) {
    vector<edge> next_v;
    if (s == g) return;
    seen[s] = true;
    printf("s: %d\n", s);
    sort(G[s].begin(), G[s].end(), [](edge a, edge b) { return a.cost < b.cost; });
    for (auto &i : G[s]) {
        if (!seen[i.to]) {
            d[i.to] = d[s] + i.cost;
            greedy(i.to, g);
        }
    }
}

int main() {
    int N;
    cin >> V >> N;
    for (int i = 0; i < N; ++i) {
        edge e1 = edge(), e2 = edge();
        int from;
        cin >> from >> e1.to >> e1.cost;
        G[from].emplace_back(e1);

        // 無向グラフなので逆方向にも辺を張る
        e2.to = from, e2.cost = e1.cost;
        G[e1.to].emplace_back(e2);
    }
    greedy(0, V - 1);
    for (int j = 0; j < V; ++j) {
        cout << d[j] << endl;
    }
    cout << d[V - 1] << endl;
    return 0;
}
