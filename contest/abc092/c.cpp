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

const int MAX_N = (int) 1e5;
ll N, A[MAX_N], diffs[MAX_N + 1], sum = 0;

void solve() {
    REP(i, N) {
        ll temp = i == 0 ? 0 : A[i - 1];
        ll temp2 = i == N - 1 ? 0 : A[i + 1];
        cout << sum - diffs[i] - diffs[i + 1] + abs(temp2 - temp) << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        if (i == 0) {
            diffs[0] = abs(A[0]);
        } else {
            diffs[i] = abs(A[i] - A[i - 1]);
        }
        if (i == N - 1) {
            diffs[N] = abs(A[i]);
            sum += diffs[N];
        }
        sum += diffs[i];
    }
    solve();
    return 0;
}
