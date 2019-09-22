#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
const ll inf = ll(1e9);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

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

void solve() {
    ll n, q;
    cin >> n >> q;
    SegmentTree<ll> tree(n, [](ll a, ll b) { return min(a, b); }, INT_MAX);
    rep(i, q) {
        ll c, x, y;
        cin >> c >> x >> y;
        if (c) {
            cout << tree.query(x, y + 1) << '\n';
        } else {
            tree.update(x, y);
        }
    }
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