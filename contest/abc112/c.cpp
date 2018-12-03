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
            REP(i, N) {
                if (h[i] == 0)continue;
                H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                REP(j, N) {
                    if (max(H - abs(x[j] - cx) - abs(y[j] - cy), ll(0)) != h[j]) break;
                    if (j == N - 1) {
                        end = true;
                        Cx = cx, Cy = cy;
                        break;
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
