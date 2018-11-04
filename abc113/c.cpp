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
const int MAX_M = int(1e5);
ll P[MAX_M + 1], Y[MAX_M + 1];
vector<ll> nums[MAX_M + 1];

void solve() {
    REP(i, M) {
        auto at = lower_bound(nums[P[i]].begin(), nums[P[i]].end(), Y[i]);
        string sp = to_string(P[i]), sdiff = to_string(at - nums[P[i]].begin() + 1);
        if (sp.length() < 6) sp = string(6 - sp.length(), '0') + sp;
        if (sdiff.length() < 6) sdiff = string(6 - sdiff.length(), '0') + sdiff;
        string ans = sp + sdiff;
        printf("%s\n", ans.c_str());
    }
}

int main() {
    cin >> N >> M;
    REP(i, M) {
        scanf("%lli %lli", &P[i], &Y[i]);
        nums[P[i]].emplace_back(Y[i]);
    }
    REPONE(i, N) {
        sort(nums[i].begin(), nums[i].end());
    }
    solve();
    return 0;
}
