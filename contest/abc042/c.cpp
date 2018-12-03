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

int N, K;
const int MAX_K = 10, MAX_N = 10000;
int D[MAX_K];
bool is_d[MAX_K];


// 1234 -> 4 3 2 1
vector<int> each_digit(int S) {
    int n_len = 0, n_dig[MAX_N];
    while (S > 0) {
        n_dig[n_len++] = S % 10;
        S /= 10;
    }
    vector<int> ret(n_dig, n_dig + n_len);
    return ret;
}

void solve() {
    each_digit(N);
    FOR(n, N, 10 * N) {
        vector<int> dig = each_digit(n);
        bool out = false;
        EACH(d, dig) {
            REP(i, K) {
                if (d == D[i]) {
                    out = true;
                    break;
                }
            }
            if (out) break;
        }
        if (out) continue;
        cout << n << endl;
        return;
    }
}

int main() {
    cin >> N >> K;
    REP(i, K) cin >> D[i];
    solve();
    return 0;
}
