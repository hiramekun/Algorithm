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

const int MAX_N = 4000;
int n, A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
int CD[MAX_N * MAX_N];

void solve() {
    // CとDからの取り出し方の組みを全列挙しておく．
    REP(i, n)REP(j, n) CD[i * n + j] = C[i] + D[j];
    sort(CD, CD + n * n);
    ll res = 0;
    REP(i, n) {
        REP(j, n) {
            int cd = -(A[i] + B[j]);
            // CとDから和がcdとなるように取り出す．
            res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
        }
    }
    cout << res << endl;
}

int main() {
    cin >> n;
    REP(i, n) cin >> A[i];
    REP(i, n) cin >> B[i];
    REP(i, n) cin >> C[i];
    REP(i, n) cin >> D[i];
    solve();
    return 0;
}
