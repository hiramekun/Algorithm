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

string X;

void solve() {
    stack<char> s;
    REP(i, X.size()) {
        if (X[i] == 'S') s.push(X[i]);
        if (X[i] == 'T' && (s.empty() || s.top() == 'T')) s.push('T');
        if (X[i] == 'T' && s.top() == 'S') s.pop();
    }
    cout << s.size() << endl;
}

int main() {
    cin >> X;
    solve();
    return 0;
}
