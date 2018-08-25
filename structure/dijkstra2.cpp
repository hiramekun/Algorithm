#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

const int INF = 1000000000;
using namespace std;
const int MAX_V = 10000;

struct edge {
    int to, cost;
};

typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

// 始点sから各頂点への最短距離を求める．
void dijkstra(int s) {
    // greater<P>を指定することでfirstが小さい順に取り出せる様にする
    priority_queue<P, vector<P>, greater<> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    return 0;
}

