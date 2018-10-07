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


const int MAX_N = 100;
int N, T;
int c[MAX_N], t[MAX_N];

void solve() {
    int c_min = INF;
    REP(i, N) {
        if (t[i] > T) continue;
        c_min = min(c_min, c[i]);
    }
    if (c_min == INF)cout << "TLE" << endl;
    else cout << c_min << endl;
}

int main() {
    cin >> N >> T;
    REP(i, N)cin >> c[i] >> t[i];
    solve();
    return 0;
}
