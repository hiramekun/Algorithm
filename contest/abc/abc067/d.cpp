#include <cstring>
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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

ll n;
const int MAX_V = half_inf;
vector<int> G[MAX_V];
vector<bool> f_seen, s_seen;


queue<int> s_bfs(queue<int> q_v) {
    queue<int> next_v;
    while (!q_v.empty()) {
        int v = q_v.front();
        q_v.pop();
        rep(i, G[v].size()) {
            if (!f_seen[G[v][i]] && !s_seen[G[v][i]]) {
                next_v.push(G[v][i]);
                s_seen[G[v][i]] = true;
            }
        }
    }
    return next_v;
}

queue<int> f_bfs(queue<int> q_v) {
    queue<int> next_v;
    while (!q_v.empty()) {
        int v = q_v.front();
        q_v.pop();
        rep(i, G[v].size()) {
            if (!s_seen[G[v][i]] && !f_seen[G[v][i]]) {
                next_v.push(G[v][i]);
                f_seen[G[v][i]] = true;
            }
        }
    }
    return next_v;
}

void solve() {
    queue<int> q_f, q_s;
    q_f.push(0), q_s.push(n - 1);
    f_seen[0] = true, s_seen[n - 1] = true;
    int f_num = 1, s_num = 1;
    while (true) {
        q_f = f_bfs(q_f);
        f_num += q_f.size();
        q_s = s_bfs(q_s);
        s_num += q_s.size();
        if (q_f.empty() && q_s.empty()) {
            if (f_num > s_num) {
                cout << "Fennec" << endl;
                return;
            } else {
                cout << "Snuke" << endl;
                return;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int s, t;
        scanf("%d %d", &s, &t);
        s--, t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    f_seen.resize(n), s_seen.resize(n);
    fill(f_seen.begin(), f_seen.end(), false), fill(s_seen.begin(), s_seen.end(), false);
    solve();
    return 0;
}
