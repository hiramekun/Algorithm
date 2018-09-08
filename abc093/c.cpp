#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int abc[3];

void solve() {
    int ans = 0;
    sort(abc, abc + 3);
    // max, minで偶奇一致
    if (abc[0] % 2 == abc[2] % 2) {
        if (abc[0] % 2 == abc[1] % 2) {
            ans = (abc[2] - abc[0]) / 2 + (abc[2] - abc[1]) / 2;
        } else {
            abc[1] = abc[2] + 1;
            ans = (abc[2] - abc[0]) / 2 + (abc[2] + 1 - abc[1]) / 2 + 1;
        }
    } else {
        if (abc[0] % 2 == abc[1] % 2) {
            ans = (abc[1] - abc[0]) / 2, abc[0] = abc[1];
            ans += abc[2] - abc[0];
        } else {
            abc[0] = abc[2] + 1;
            ans = (abc[2] - abc[1]) / 2 + (abc[2] + 1 - abc[0]) / 2 + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    REP(i, 3) cin >> abc[i];
    solve();
    return 0;
}
