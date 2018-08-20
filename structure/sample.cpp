#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int MAX_V = 1000;
vector<int> G[MAX_V];
int E;

int main() {
    cin >> E;
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        G[t].push_back(s);
    }
    for (int i = 0; i < E; ++i) {
        printf("number: %d\n", i);
        for (int j = 0; j < G[i].size(); ++j) {
            printf("%d\n", G[i][j]);
        }
    }
    return 0;
}

