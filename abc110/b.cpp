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
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int N, M, X, Y;

void solve() {
}

int main() {
    cin >> N >> M >> X >> Y;
    int x[N], y[M];
    int max_x = -INF, min_y = INF;

    REP(i, N) {
        cin >> x[i];
        max_x = max(max_x, x[i]);
    }
    REP(i, M) {
        cin >> y[i];
        min_y = min(min_y, y[i]);
    }
    if (max_x > min_y) {
        cout << "War" << endl;
        return 0;
    }
    FOR(i, max_x + 1, min_y + 1) {
        if (X < i && i <= Y) {
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    return 0;
}
