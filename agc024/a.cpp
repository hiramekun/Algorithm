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

ll A, B, C;
ll K;

void solve() {
    ll ab = pow(-1, K) * (pow(-2, K - 1) * (-2 / 3) - 1 / 3);
    ll aa = K % 2 == 0 ? ab + 1 : ab - 1;
    ll tscore = aa * A + ab * B + ab * C;
    ll nscore = aa * B + ab * C + ab * A;
    cout << tscore - nscore << endl;
}

int main() {
    cin >> A >> B >> C >> K;
    solve();
    return 0;
}
