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
    cin >> Q;
    REP(i, Q) {
        cin >> L[i] >> R[i];
        int res = L[i], ans = 0;
        while (res < R[i]) {
            int prex = mp[res].first, prey = mp[res].second;
            res += D;
            int x = mp[res].first, y = mp[res].second;
            ans += abs(x - prex) + abs(y - prey);
        }
        printf("%d\n",ans);
    }
    return 0;
}
