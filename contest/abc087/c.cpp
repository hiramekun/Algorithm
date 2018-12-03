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

const int MAX_N = 100;
int N;
int A[2][MAX_N], nums[2 + 1][MAX_N + 1];


void solve() {
    REP(i, 2) {
        REP(j, N) {
            if (i == 0) {
                nums[0][j + 1] = nums[0][j] + A[i][j];
            } else {
                nums[1][j + 1] = max(nums[0][j + 1] + A[i][j], nums[1][j] + A[i][j]);
            }
        }
    }
    cout << nums[1][N] << endl;
}

int main() {
    cin >> N;
    REP(i, 2) REP(j, N) {
            cin >> A[i][j];
        }
    solve();
    return 0;
}
