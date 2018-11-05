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
//typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N, M;
const unsigned int MAX_M = static_cast<unsigned int>(1e5);
ll P[MAX_M + 1], Y[MAX_M + 1];
vector<vector<pair<ll, ll>>> v(MAX_M + 1);

void solve() {
    vector<pair<ll, ll>> ans(M);
    FOR(i, 1, N + 1) {
        // 各市ごとにsort
        sort(v[i].begin(), v[i].end());
        // sortした配列を最初から見ていく
        // ans[配列の入力順]に市番号, 順番を加える
        REP(j, v[i].size()) ans[v[i][j].second] = make_pair(i, j + 1);
    }

    REP(i, M) printf("%06lli%06lli\n", ans[i].first, ans[i].second);
}

int main() {
    cin >> N >> M;
    REP(i, M) {
        scanf("%lli %lli", &P[i], &Y[i]);
        // 各市ごとにベクトルに値を加える
        v[P[i]].emplace_back(make_pair(Y[i], i));
    }
    solve();
    return 0;
}
