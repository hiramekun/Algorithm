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
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int MAX_N = 100;
int N;
ll x[MAX_N], y[MAX_N], h[MAX_N];
ll Cx, Cy, H;

void solve() {
    bool end = false;
    REP(cx, 100 + 1) {
        REP(cy, 100 + 1) {
            REP(j, N - 1) {
                if (h[j] == 0 || h[j + 1] == 0) continue;
                if (abs(x[j + 1] - cx) + abs(y[j + 1] - cy) - abs(x[j] - cx) - abs(y[j] - cy) ==
                    h[j] - h[j + 1]) {

                    REP(i, N - 1) {
                        if (h[i] != 0 && h[i + 1] != 0) {
                            if (abs(x[i + 1] - cx) + abs(y[i + 1] - cy) - abs(x[i] - cx) -
                                abs(y[i] - cy) != h[i] - h[i + 1]) {
                                break;
                            }
                        }
                        if (h[i] != 0) H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                        if (h[i + 1] != 0) H = h[i + 1] + abs(x[i + 1] - cx) + abs(y[i + 1] - cy);

                        if (((h[i] == 0 || h[i + 1] == 0) ||
                             abs(x[i + 1] - cx) + abs(y[i + 1] - cy) - abs(x[i] - cx) -
                             abs(y[i] - cy) == h[i] - h[i + 1]) && i == N - 2) {
                            end = true;
                            Cx = cx, Cy = cy;
                            break;
                        }
                    }
                }
                if (end) break;
            }
            if (end) break;
        }
        if (end) break;
    }
    cout << Cx << ' ' << Cy << ' ' << H << endl;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> x[i] >> y[i] >> h[i];
    }
    solve();
    return 0;
}
