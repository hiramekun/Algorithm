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


const int MAX_N = 2 * (int) 1e5;
ll N, A[MAX_N], A1[MAX_N];

void solve() {
    sort(A1, A1 + N);
    ll b = A1[N / 2];
    ll ans = 0;
    REP(i, N) ans += abs(A1[i] - b);
    cout << ans << endl;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        A1[i] = A[i] - (i + 1);
    }
    solve();
    return 0;
}

