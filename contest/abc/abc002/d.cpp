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

const int MAX_N = 12, MAX_M = 12 * 11 / 2;
int N, M, x[MAX_M], y[MAX_M];

void solve() {
    int ans = 1;
    REP(i, pow(2, N)) {
        vector<int> use_num;
        REP(j, N) if ((1 & i >> j) == 1) use_num.emplace_back(j);
        REP(v, use_num.size()) {
            int all = 0;
            REP(m, M) {
                if (use_num[v] == x[m]) EACH(w, use_num) if (y[m] == w)all++;
                if (use_num[v] == y[m]) EACH(w, use_num) if (x[m] == w)all++;
            }
            if (all != use_num.size() - 1) break;
            if (v == use_num.size() - 1) {
                ans = max((int) use_num.size(), ans);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> M;
    REP(i, M) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    solve();
    return 0;
}

