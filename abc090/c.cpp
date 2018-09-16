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

ll N, M;

void solve() {
    if (N == 2 || M == 2) {
        cout << 0 << endl;
        return;
    }
    if (N == 1 && M == 1) {
        cout << 1 << endl;
        return;
    }
    if (N == 1) {
        cout << M - 2 << endl;
        return;
    } else if (M == 1) {
        cout << N - 2 << endl;
        return;
    } else {
        cout << N * M - (2 * M + 2 * (N - 2)) << endl;
        return;
    }
}

int main() {
    cin >> N >> M;
    solve();
    return 0;
}
