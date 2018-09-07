#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF (1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int MAX_N = (int) 1e5;
int N, K, X[MAX_N];

void solve() {
    int ans = (int) INF;
    REP(i, N - K + 1) {
        int small = X[i], big = X[i + K - 1];
        ans = min(ans, min(abs(small) + abs(big - small), abs(big) + abs(big - small)));
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> X[i];
    solve();
    return 0;
}
