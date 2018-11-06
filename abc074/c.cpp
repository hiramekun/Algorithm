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

int a, b, c, d, e, f;

void solve() {
    double d_max = -INF;
    int w_ans = 0, s_ans = 0;
    REP(i, f / 100 + 1)REP(j, f / 100 + 1)REP(k, f / c + 1)REP(l, f / d + 1) {
                    double w = 100 * a * i + 100 * b * j, s = c * k + d * l;
                    if (w + s <= f && s / w <= double(e) / 100) {
                        if (s / (s + w) > d_max) {
                            d_max = s / (s + w);
                            w_ans = (int) w, s_ans = (int) s;
                        }
                    }
                }
    printf("%d %d", w_ans + s_ans, s_ans);
}

int main() {
    cin >> a >> b >> c >> d >> e >> f;
    solve();
    return 0;
}
