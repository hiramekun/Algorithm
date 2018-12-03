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


const int MAX_Q = int(1e5);
int H, W, D, Q, L[MAX_Q], R[MAX_Q];
unordered_map<int, pair<int, int> > mp;

int main() {
    cin >> H >> W >> D;
    int temp;
    REP(i, H) {
        REP(j, W) {
            cin >> temp;
            mp[temp] = make_pair(i, j);
        }
    }
    ll dp[H * W + 1];
    FOR(i, D + 1, H * W + 1) {
        ll pre_x = mp[i - D].first, pre_y = mp[i - D].second;
        ll x = mp[i].first, y = mp[i].second;
        dp[i] = dp[i - D] + abs(x - pre_x) + abs(y - pre_y);
    }
    cin >> Q;
    REP(i, Q) {
        cin >> L[i] >> R[i];
        printf("%lli\n", dp[R[i]] - dp[L[i]]);
    }
    return 0;
}
