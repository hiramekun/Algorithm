/**
 * Created by hiramekun at 20:20 on 2019-09-24.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

// 区間加算, 区間和
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
template<typename Monoid, typename Action>
struct SegmentTree {
public:
    using FM = function<Monoid(Monoid, Monoid)>; // monoid
    using FL = function<Action(Action, Action)>; // lazy
    using FA = function<Monoid(Monoid, Action)>; // action
    using FW = function<Action(Action, ll)>; // action

    // O(N)
    SegmentTree(int n, const FM fm, const FL fl, const FA fa, const FW fw, Monoid M1, Action A1)
            : fm(fm), fl(fl), fa(fa), fw(fw), M1(M1), A1(A1) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz - 1, M1);
        lazy.assign(2 * sz - 1, A1);
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

void solve() {
    ll n, q;
    cin >> n >> q;
    auto fm = [](ll a, ll b) { return a + b; };
    auto fl = [](ll a, ll b) { return a + b; };
    auto fa = [](ll a, ll b) { return a + b; };
    auto fw = [](ll a, ll w) { return a * w; };
    SegmentTree<ll, ll> tree(n, fm, fl, fa, fw, 0, 0);
    rep(i, q) {
        ll c;
        cin >> c;
        if (c) {
            ll s, t;
            cin >> s >> t;
            s--, t--;
            cout << tree.query(s, t + 1) << '\n';
        } else { // add
            ll s, t, x;
            cin >> s >> t >> x;
            s--, t--;
            tree.update(s, t + 1, x);
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
