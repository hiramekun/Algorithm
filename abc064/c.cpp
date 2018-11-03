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

bool used[8];
int N, num_big = 0;

void solve() {
    int ans_max = 0, ans_min = 0;
    REP(i, 8) if (used[i]) ans_min++, ans_max++;
    ans_max += num_big;
    if (ans_min == 0 && num_big > 0) ans_min++;

    printf("%d %d\n", ans_min, ans_max);
}

int main() {
    cin >> N;
    int temp;
    REP(i, N) {
        cin >> temp;
        if (temp < 3200) used[temp / 400] = true;
        else num_big++;
    }
    solve();
    return 0;
}
