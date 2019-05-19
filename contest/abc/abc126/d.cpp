#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <numeric>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef unordered_map<string, ll> mpsl;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

string ins() {
    string x;
    cin >> x;
    return (x);
}

const int MAX_V = 1e5;

struct edge {
    int to, cost;

    edge(int to, int cost) : to(to), cost(cost) {}
};

vector<edge> G[MAX_V];
vector<bool> seen(MAX_V, false);
vector<bool> isB(MAX_V, false);

void dfs(int idx, bool b) {
    seen[idx] = true;
    isB[idx] = b;

    for (int i = 0; i < G[idx].size(); ++i) {
        if (seen[G[idx][i].to]) continue;
        if (G[idx][i].cost % 2 == 0) dfs(G[idx][i].to, b);
        else dfs(G[idx][i].to, !b);
    }
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n = inl();
        rep(i, n - 1) {
            ll u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            edge e1(u, w);
            edge e2(v, w);
            G[v].eb(e1);
            G[u].eb(e2);
        }
        rep(i, n) {
            if (!seen[i]) dfs(i, false);
        }
        rep(i, n) {
            if (isB[i]) cout << 1 << endl;
            else cout << 0 << endl;
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}