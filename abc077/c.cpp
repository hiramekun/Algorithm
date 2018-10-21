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
ll N, A[MAX_N], B[MAX_N], C[MAX_N];

void solve() {
    sort(A, A + N);
    sort(C, C + N);

    ll ans = 0;
    REP(i, N) {
        ll *up_b = upper_bound(A, A + N, B[i] - 1);
        ll *up_c = upper_bound(C, C + N, B[i]);
        ans += (up_b - A) * (C + N - up_c);
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];
    solve();
    return 0;
}
