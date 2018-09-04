//
// Created by Takaaki Hirano on 2018/09/03.
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

int D, G;
const int MAX_D = 100;
int p[MAX_D], c[MAX_D];


void solve() {
    int ans = INF;
    REP(i, pow(2, D)) {
        int count = 0, score = 0;
        REP(j, D) {
            if ((1 & i >> j) == 1) {
                score += p[j] * 100 * (j + 1) + c[j];
                count += p[j];
            }
        }
        REPR(j, D) {
            if ((1 & i >> j) == 1)continue;
            REP(k, p[j]) {
                if (score >= G)break;
                score += 100 * (j + 1);
                count++;
            }
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
}

int main() {
    cin >> D >> G;
    REP(i, D)cin >> p[i] >> c[i];
    solve();
    return 0;
}

