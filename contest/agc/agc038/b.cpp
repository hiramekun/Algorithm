/**
 * Created by hiramekun at 20:53 on 2019-09-21.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}

template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

// https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
// verified with http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
template<typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    // O(N)
    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    // O(logN)
    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    // O(logN)
    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
};

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

void solve() {
    ll n, k;
    cin >> n >> k;
    vl p(n);
    cin >> p;
    ll same = 0, cont = 0;
    rep(i, n) {
        ll c = 0;
        while (i + 1 < n && p[i] < p[i + 1]) {
            c++;
            i++;
        }
        ll tmp = max(0LL, (c - k + 2));
        same += tmp;
        cont += max(0LL, tmp - 1);
    }
    SegmentTree<ll> minTree(n, [](ll a, ll b) { return min(a, b); }, INT_MAX);
    SegmentTree<ll> maxTree(n, [](ll a, ll b) { return max(a, b); }, INT_MIN);
    rep(i, n) {
        minTree.update(i, p[i]);
        maxTree.update(i, p[i]);
    }

    ll prev_min = ll_inf, prev_max = ll_inf;
    ll ans = 0;
    rep(i, n - k + 1) {
        ll mi = minTree.query(i, i + k);
        ll mx = maxTree.query(i, i + k);
        if ((prev_min < mi && prev_max < mx));
        else ans++;
        prev_min = mi, prev_max = mx;
    }
    if (same > 0) {
        ans -= (same - cont);
        ans++;
    }
    cout << max(1LL, ans) << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}
