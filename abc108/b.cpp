//
// Created by Takaaki Hirano on 2018/09/01.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
int x[2], y[2];

void solve() {
    int vec_x = x[1] - x[0];
    int vec_y = y[1] - y[0];
    int vecx3 = -vec_y;
    int vecy3 = vec_x;
    int x4 = x[0] + vecx3;
    int y4 = y[0] + vecy3;
    int x3 = x4 + vec_x;
    int y3 = y4 + vec_y;
    printf("%d %d %d %d", x3, y3, x4, y4);
}

int main() {
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    solve();
    return 0;
}

