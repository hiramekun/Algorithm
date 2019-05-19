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

struct xyz {
    ll x, y, z;
};
vector<int> G[int(1e5)];
vector<bool> seen(int(1e5), false);
ll ans = 0;

void dfs(int idx) {
    seen[idx] = true;
    for (int i = 0; i < G[idx].size(); ++i) {
        if (seen[G[idx][i]])continue;
        dfs(G[idx][i]);
    }
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n = inl(), m = inl();
        vector<xyz> a;
        rep(i, m) {
            xyz tmp;
            tmp.x = inl(), tmp.y = inl(), tmp.z = inl();
            tmp.x--, tmp.y--;
            a.eb(tmp);
            G[tmp.x].eb(tmp.y);
            G[tmp.y].eb(tmp.x);
        }
        for (int i = 0; i < n; ++i) {
            if (seen[i]) continue;
            ans++;
            dfs(i);
        }
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}