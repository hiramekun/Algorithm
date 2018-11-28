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

void dijkstra(int s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<> > que;
    fill(d, d + V, 1e9);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); // queから最短距離が最小のものを取り出す
        que.pop();
        int v = p.second; // 最短距離が最小のものの頂点
        if (d[v] < p.first) continue; // すでに最短距離が小さければ
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                // 頂点vから張っている頂点への最短距離を求め，それを次にqueに入れる．
                que.push(P(d[e.to], e.to));
            }
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
    dijkstra(0);
    printf("answer of cost is %d", d[V - 1]);
    return 0;
}
