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

const int MAX_N = 1000;
int N, T, A;
double H[MAX_N];

int main() {
    cin >> N >> T >> A;
    auto temp_ans = double(INF);
    int ans = 0;
    REP(i, N) {
        cin >> H[i];
        H[i] = abs(A - (double(T) - H[i] * 0.006));
        if (H[i] < temp_ans) {
            temp_ans = H[i];
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}