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
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


const int MAX_N = 1000;
int N;
ll T[MAX_N], A[MAX_N];

void solve() {
    ll t = 1, a = 1;
    REP(i, N) {
        if (i == 0) {
            t = T[i], a = A[i];
            continue;
        }
        if (t < T[i]) t = T[i];
        if (a < A[i]) a = A[i];
        if (t > T[i] && t % T[i] != 0) t += (T[i] - t % T[i]);
        if (a > A[i] && a % A[i] != 0) a += (A[i] - a % A[i]);
        if (t / T[i] > a / A[i]) {
            a = t / T[i] * A[i];
        } else if (a / A[i] > t / T[i]) {
            t = a / A[i] * T[i];
        }
    }
    cout << t + a << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> T[i] >> A[i];
    solve();
    return 0;
}
