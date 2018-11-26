#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll x, y;

void solve() {
    if (y > x) {
        if (x * y >= 0) {
            cout << abs((abs(y) - abs(x))) << endl;
        } else {
            cout << abs(abs(y) - abs(x)) + 1 << endl;
        }
    } else {
        if (x * y == 0) {
            cout << abs(x) + abs(y) + 1 << endl;
        } else if (x * y > 0) {
            cout << (abs(abs(x) - abs(y))) + 2 << endl;
        } else {
            cout << (abs(abs(y) - abs(x))) + 1 << endl;
        }
    }
}

int main() {
    cin >> x >> y;
    solve();
    return 0;
}
