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

struct abc {
    ll sum, ia, ib, ic;
};

bool operator<(const abc &abc1, const abc &abc2) {
    return abc1.sum < abc2.sum;
};

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll x = inl(), y = inl(), z = inl(), k = inl();
        vl a(x), b(y), c(z);
        rep(i, x) a[i] = inl();
        rep(i, y) b[i] = inl();
        rep(i, z) c[i] = inl();

        sort(all(a), greater<>());
        sort(all(b), greater<>());
        sort(all(c), greater<>());
        PQ<abc> que;
        que.push({a[0] + b[0] + c[0], 0, 0, 0});
        vl ans;

        set<ll> s;
        rep(i, k) {
            abc v = que.top();
            que.pop();
            ans.eb(v.sum);

            if (v.ia != x - 1) {
                ll na = v.ia + 1;
                ll hash = (na << 20) + (v.ib << 10) + v.ic;
                if (s.find(hash) == s.end()) {
                    s.insert(hash);
                    que.push({a[na] + b[v.ib] + c[v.ic], na, v.ib, v.ic});
                }
            }
            if (v.ib != y - 1) {
                ll nb = v.ib + 1;
                ll hash = (v.ia << 20) + (nb << 10) + v.ic;
                if (s.find(hash) == s.end()) {
                    s.insert(hash);
                    que.push({a[v.ia] + b[nb] + c[v.ic], v.ia, nb, v.ic});
                }
            }
            if (v.ic != z - 1) {
                ll nc = v.ic + 1;
                ll hash = (v.ia << 20) + (v.ib << 10) + nc;
                if (s.find(hash) == s.end()) {
                    s.insert(hash);
                    que.push({a[v.ia] + b[v.ib] + c[nc], v.ia, v.ib, nc});
                }
            }
        }
        rep(i, k) cout << ans[i] << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}