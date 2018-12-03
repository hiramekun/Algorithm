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


int N;
int a_dig[int(1e5)];
int b_dig[int(1e5)];

int a_digit(int S) {
    int s_len = 0;
    while (S > 0) {
        a_dig[s_len++] = S % 10;
        S /= 10;
    }
    return s_len;
}

int b_digit(int S) {
    int s_len = 0;
    while (S > 0) {
        b_dig[s_len++] = S % 10;
        S /= 10;
    }
    return s_len;
}

void solve() {
    int ans = INF;
    REPONE(i, N - 1) {
        int A = i, B = N - i;
        int len_a = a_digit(A);
        int res = 0;
        REP(j, len_a) res += a_dig[j];
        int len_b = b_digit(B);
        REP(k, len_b) res += b_dig[k];
        ans = min(ans, res);
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    solve();
    return 0;
}
