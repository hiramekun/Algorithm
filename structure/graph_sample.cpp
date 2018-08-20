#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int MAX_V = 100;
vector<int> G[MAX_V];

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; ++i) {
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
    }
    return 0;
}

