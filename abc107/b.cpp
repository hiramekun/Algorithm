#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
const int MAX_W = 100;
int H, W;
char as[MAX_W][MAX_W];
bool has_sharp_row[MAX_W];
bool has_sharp_column[MAX_W];


void solve() {
    for (int h = 0; h < H; ++h) {
        bool printed = false;
        for (int w = 0; w < W; ++w) {
            if (has_sharp_column[w] && has_sharp_row[h]) {
                printed = true;
                printf("%c", as[h][w]);
            }
        }
        if (printed) printf("\n");
    }
}

int main() {
    cin >> H >> W;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            cin >> as[h][w];
            if (as[h][w] == '#') has_sharp_column[w] = has_sharp_row[h] = true;
        }
    }
    solve();
    return 0;
}
