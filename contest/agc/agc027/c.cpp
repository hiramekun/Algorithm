#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

const int MAX_N = 2 * (int) 1e5;
vector<int> G[MAX_N];
int N, M;
bool used[MAX_N];
string s;

bool dfs(int v) {

    bool has_diff = false, has_same = false;
    vector<int> next;
    REP(i, G[v].size()) {
        if (s[v] == s[G[v][i]]) {
            has_same = true;
            next.emplace_back(i);
        } else {
            has_diff = true;
            next.emplace_back(i);
        }
    }
    if (has_same && has_diff) {
        if (used[v]) return true;
        used[v] = true;
        EACH(i, next) if (dfs(i)) return true;
        return false;
    } else {
        used[v] = true;
        return false;
    }
}

void solve() {
    REP(i, N) {
        if (dfs(i)) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    cin >> N >> M >> s;
    fill(used, used + N, false);
    int a, b;
    REP(i, M) {
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    solve();
    return 0;
}
