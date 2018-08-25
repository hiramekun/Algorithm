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

void solve() {
    char ans[H][W];
    char tempw[W];
    int temp = 0;

    for (int h = 0; h < H; ++h) {
        int count = 0;
        for (int w = 0; w < W; ++w) {
            if (as[h][w] == '.') {
                count++;
            }
            tempw[w] = as[h][w];
        }
        if (count != W) {
            for (int w = 0; w < W; ++w) {
                ans[h][w] = tempw[w];
            }
        } else {
            temp++;
        }
    }

    char finalans[H][W];
    char temph[H];
    int temp2 = 0;
    for (int w = 0; w < W; ++w) {
        int count = 0;
        for (int h = 0; h < H; ++h) {
            if (ans[h][w] == '.') {
                count++;
            }
            temph[h] = ans[h][w];
        }
        if (count != H - temp) {
            for (int h = 0; h < H; ++h) {
                finalans[h][w] = temph[h];
            }
        } else {
            temp2++;
        }
    }
    for (int i = 0; i < H; ++i) {
        bool haschar = false;
        for (int j = 0; j < W; ++j) {
            if (finalans[i][j] == '.' || finalans[i][j] == '#') {
                haschar = true;
                printf("%c", finalans[i][j]);
            }
            if (haschar && j == W - 1) printf("\n");
        }
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
