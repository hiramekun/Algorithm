#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int MAX_H = 100;
int H, W;
char as[MAX_H][MAX_H];
bool remove_w[MAX_H];
bool remove_h[MAX_H];

void solve() {
    for (int h = 0; h < H; ++h) {
        int count = 0;
        for (int w = 0; w < W; ++w) if (as[h][w] == '.') count++;
        if (count == W) remove_w[h] = true;
    }
    for (int w = 0; w < W; ++w) {
        int count = 0;
        for (int h = 0; h < H; ++h) if (as[h][w] == '.') count++;
        if (count == H) remove_h[w] = true;
    }

    for (int h = 0; h < H; ++h) {
        if (remove_w[h]) continue;
        for (int w = 0; w < W; ++w) {
            if (remove_h[w]) continue;
            printf("%c", as[h][w]);
        }
        printf("\n");
    }
}

int main() {
    cin >> H >> W;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            cin >> as[h][w];
        }
    }
    solve();
    return 0;
}
