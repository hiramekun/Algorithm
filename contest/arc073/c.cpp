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

const int MAX_N = 2 * int(1e5);
int N;
ll T, t[MAX_N], dp = 0;

int main() {
    cin >> N >> T;
    REP(i, N) {
        cin >> t[i];
        if (i == 0) dp += T;
        else if (t[i - 1] + T < t[i]) dp += T;
        else dp += (t[i] - t[i - 1]);
    }
    cout << dp << endl;
    return 0;
}
