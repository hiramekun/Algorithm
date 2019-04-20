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

ll a[500][500];
ll n;
ll m;

bool dfs(ll cur, ll idx_now, vl his) {
    if (idx_now == n) {
        return cur != 0;
    }
    for (int i = 0; i < m; ++i) {
        his.eb(i);
        if (dfs(cur ^ a[idx_now][i], idx_now + 1, his)) return true;
    }
    return false;
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        n = inl();
        m = inl();

        vector<set<ll>> s(n);
        ll idxs[500][1024];
        rep(i, n) {
            rep(j, m) {
                cin >> a[i][j];
                s[i].insert(a[i][j]);
                idxs[i][a[i][j]] = j + 1;
            }
        }
        ll ans = 0;
        vl ians;
        rep(i, n) {
            ll tmp = *(s[i].begin());
            ians.eb(idxs[i][tmp]);
            ans ^= tmp;
        }
        if (ans == 0) {
            bool use = false;
            ians.clear();
            rep(i, n) {
                if (use || s[i].size() == 1) {
                    ll tmp = *(s[i].begin());
                    ans ^= tmp;
                    ians.eb(idxs[i][tmp]);
                } else {
                    ll tmp = *(s[i].rbegin());
                    use = true;
                    ans ^= tmp;
                    ians.eb(idxs[i][tmp]);
                }
            }
        }
        if (ans == 0) cout << "NIE" << endl;
        else {
            cout << "TAK" << endl;
            each(v, ians) printf("%lli ", v);
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}