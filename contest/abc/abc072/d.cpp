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

const int MAX_N = int(1e5);
int N, p[MAX_N];

void solve() {
    ll ans = 0;
    REP(i, N) {
        if (i != p[i]) continue;
        if (p[i + 1] == i + 1) {
            ans += 1;
            swap(p[i], p[i + 1]);
        } else if (p[i - 1] == i - 1) {
            ans += 1;
            swap(p[i], p[i - 1]);
        } else {
            ans += 1;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> p[i];
        p[i]--;
    }
    solve();
    return 0;
}
