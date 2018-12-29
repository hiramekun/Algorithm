//
// Created by Takaaki Hirano on 2018/09/05.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int abc[3], X, Y;

void solve() {
    int A = abc[0], B = abc[1], C = abc[2];
    int normal = A * X + B * Y;
    if (X > Y) {
        cout << min(X * 2 * C, min(Y * 2 * C + max(X - Y, 0) * A, normal)) << endl;
    } else {
        cout << min(Y * 2 * C, min(X * 2 * C + max(Y - X, 0) * B, normal)) << endl;
    }
}

int main() {
    REP(i, 3)cin >> abc[i];
    cin >> X >> Y;
    solve();
    return 0;
}

