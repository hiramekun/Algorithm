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

ll N, M;
const ll DIV = ll(1e9) + 7;

ll factorial(ll n) {
    if (n == 1) return n % DIV;
    return ((n % DIV) * factorial(n - 1)) % DIV;
}

void solve() {
    if (abs(N - M) > 1) {
        cout << 0 << endl;
        return;
    }
    if (N == M) {
        cout << (2 * factorial(N) * factorial(M)) % DIV << endl;
    } else {
        cout << (factorial(M) * factorial(N)) % DIV << endl;
    }
}

int main() {
    cin >> N >> M;
    solve();
    return 0;
}
