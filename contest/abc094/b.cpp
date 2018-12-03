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

const int MAX_M = 100;
int N, M, X, A[MAX_M];


void solve() {
    int ans1 = 0;
    int ans2 = 0;
    FOR(i, X, N) {
        REP(j, M) if (i == A[j]) ans1++;
    }
    REPR(i, X) {
        REP(j, M) if (i == A[j]) ans2++;
    }
    cout << min(ans1, ans2) << endl;
}

int main() {
    cin >> N >> M >> X;
    REP(i, M) cin >> A[i];
    solve();
    return 0;
}
