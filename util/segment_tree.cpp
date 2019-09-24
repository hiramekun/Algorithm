#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

// sample: http://beet-aizu.hatenablog.com/entry/2017/12/01/225955
// verified with
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
template<typename Monoid, typename Action>
struct SegmentTree {
public:
    // mergeするときの操作
    using FM = function<Monoid(Monoid, Monoid)>;
    // lazyをxでupdate
    using FL = function<Action(Action, Action)>;
    // dataにlazyでupdate
    using FA = function<Monoid(Monoid, Action)>;
    // lenが与えられた時にlazyを計算
    using FW = function<Action(Action, ll)>;

    // O(N)
    SegmentTree(int n, const FM fm, const FL fl, const FA fa, const FW fw, Monoid M1, Action A1)
            : fm(fm), fl(fl), fa(fa), fw(fw), M1(M1), A1(A1) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz - 1, M1);
        lazy.assign(2 * sz - 1, A1);
    }

    void build(vector<Monoid> v) {
        rep(i, sz) seg[i + sz - 1] = v[i];
        for (ll i = sz - 2; i >= 0; --i) {
            seg[i] = fm(seg[i * 2 + 1], seg[i * 2 + 2]);
        }
    }

    // O(logN)
    Monoid update(int a, int b, Monoid x) {
        return update(a, b, x, 0, 0, sz);
    }

    // O(logN)
    Monoid query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }


    int sz;
    vector<Monoid> seg;
    vector<Action> lazy;

private:
    const FM fm;
    const FL fl;
    const FA fa;
    const FW fw;
    const Monoid M1;
    const Action A1;

    void eval(int len, int k) {
        if (lazy[k] == A1) return;
        if (k * 2 + 1 < sz * 2 - 1) {
            lazy[2 * k + 1] = fl(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = fl(lazy[2 * k + 2], lazy[k]);
        }
        seg[k] = fa(seg[k], fw(lazy[k], len));
        lazy[k] = A1;
    }

    Monoid update(int a, int b, Monoid x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a || b <= l) return seg[k];
        if (a <= l && r <= b) {
            lazy[k] = fl(lazy[k], x);
            return fa(seg[k], fw(lazy[k], r - l));
        }
        return seg[k] = fm(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                           update(a, b, x, k * 2 + 2, (l + r) / 2, r));
    }

    Monoid query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a || b <= l) return M1;
        if (a <= l && r <= b) return seg[k];
        Monoid vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        Monoid vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return fm(vl, vr);
    }
};

// 値更新, 区間最小
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
void solve() {
    ll n, q;
    cin >> n >> q;
    auto fm = [](ll a, ll b) { return min(a, b); };
    auto fl = [](ll a, ll b) { return b; };
    auto fa = [](ll a, ll b) { return b; };
    auto fw = [](ll a, ll w) { return a; };
    SegmentTree<ll, ll> tree(n, fm, fl, fa, fw, INT_MAX, INT_MAX);
    rep(i, q) {
        ll c, x, y;
        cin >> c >> x >> y;
        if (c) {
            cout << tree.query(x, y + 1) << '\n';
        } else {
            tree.update(x, x + 1, y);
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