#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

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
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); // queから最短距離が最小のものを取り出す
        que.pop();
        int v = p.second; // 最短距離が最小のものの頂点
        if (d[v] < p.first) continue; // すでに最短距離が小さければ
        REP(i, G[v].size()) {
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
    return 0;
}
