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

const int MAX_P = int(1e6);
int P, a[MAX_P];

void solve() {
    set<int> all; // 書かれている事柄の総数を計算．
    REP(i, P) all.insert(a[i]);
    int n = int(all.size());
    int s = 0, t = 0, num = 0;
    map<int, int> count; // 事柄 -> 出現数の対応.
    int res = P;
    for (;;) {
        while (t < P && num < n) if (count[a[t++]]++ == 0) num++; // 0 -> 1になった時
        if (num < n) break;
        res = min(res, t - s);
        if (--count[a[s++]] == 0) num--; // 1 -> 0になった時
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
