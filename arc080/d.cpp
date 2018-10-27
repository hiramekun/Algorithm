#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_H = 100;
const int MAX_N = MAX_H * MAX_H;
int H, W, N, a[MAX_N];

void solve() {
    int now_c = 0;
    int ans[H][W];
    REP(h, H) {
        if (h % 2 == 0) {
            REP(w, W) {
                if (a[now_c] == 0) now_c++;
                a[now_c]--;
                ans[h][w] = now_c + 1;
            }
        } else {
            REPR(w, W) {
                if (a[now_c] == 0) now_c++;
                a[now_c]--;
                ans[h][w] = now_c + 1;
            }
        }
    }
    REP(h, H) {
        REP(w, W) {
            printf("%d ", ans[h][w]);
        }
        printf("\n");
    }
}

int main() {
    cin >> H >> W >> N;
    REP(i, N) cin >> a[i];
    solve();
    return 0;
}
