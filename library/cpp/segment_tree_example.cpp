/**
 * Created by hiramekun at 00:41 on 2020-06-07.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

// sample: http://beet-aizu.hatenablog.com/entry/2017/12/01/225955
// verified with
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
template<typename Data, typename Lazy>
struct SegmentTree {
public:
    bool isLazy = false;
    int sz;
    vector<Data> seg;
    vector<Lazy> lazy;

    // mergeするときの操作
    using MergeData = function<Data(Data, Data)>;
    // lazyをxでupdate
    using UpdateLazyFromX = function<Lazy(Lazy, Lazy)>;
    // dataをlazyでupdate
    using UpdateDataFromLazy = function<Data(Data, Lazy)>;
    // lenが与えられた時にlazyを計算
    using CalcLazyWithLen = function<Lazy(Lazy, ll)>;

    // lazy
    // O(N)
    SegmentTree(int n, const MergeData fm, const UpdateLazyFromX fl, const UpdateDataFromLazy fa,
                const CalcLazyWithLen fw, Data M1, Lazy A1)
            : fm(fm), fl(fl), fa(fa), fw(fw), M1(M1), A1(A1) {
        isLazy = true;
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz - 1, M1);
        lazy.assign(2 * sz - 1, A1);
    }

    // not lazy
    SegmentTree(int n, const MergeData fm, Data M1) :
            fm(fm), M1(M1),
            // ここからdummy
            fl([M1](Data a, Data b) { return M1; }),
            fa([M1](Data a, Lazy b) { return M1; }),
            fw([M1](Lazy a, ll b) { return M1; }),
            A1(M1) {
        isLazy = false;
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz - 1, M1);
    }

    // not lazy
    // O(logN)
    Data update(int i, Data x) {
        i += sz - 1;
        seg[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            seg[i] = fm(seg[2 * i + 1], seg[2 * i + 2]);
        }
    }

    void build(const vector<Data> &v) {
        ll n = v.size();
        rep(i, n) seg[i + sz - 1] = v[i];
        for (ll i = sz - 2; i >= 0; --i) {
            seg[i] = fm(seg[i * 2 + 1], seg[i * 2 + 2]);
        }
    }

    // for lazy only
    // O(logN)
    Data update(int a, int b, Data x) {
        return update(a, b, x, 0, 0, sz);
    }

    // O(logN)
    Data query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }

private:
    const MergeData fm;
    const UpdateLazyFromX fl;
    const UpdateDataFromLazy fa;
    const CalcLazyWithLen fw;
    const Data M1;
    const Lazy A1;

    void eval(int len, int k) {
        if (lazy[k] == A1) return;
        if (k * 2 + 1 < sz * 2 - 1) {
            lazy[2 * k + 1] = fl(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = fl(lazy[2 * k + 2], lazy[k]);
        }
        seg[k] = fa(seg[k], fw(lazy[k], len));
        lazy[k] = A1;
    }

    Data update(int a, int b, Data x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a || b <= l) return seg[k];
        if (a <= l && r <= b) {
            lazy[k] = fl(lazy[k], x);
            return fa(seg[k], fw(lazy[k], r - l));
        }
        return seg[k] = fm(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                           update(a, b, x, k * 2 + 2, (l + r) / 2, r));
    }

    Data query(int a, int b, int k, int l, int r) {
        if (isLazy) eval(r - l, k);
        if (r <= a || b <= l) return M1;
        if (a <= l && r <= b) return seg[k];
        Data vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        Data vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return fm(vl, vr);
    }
};

SegmentTree<ll, ll> RangeMinimumTree(int n) {
    auto fm = [](ll a, ll b) { return min(a, b); };
    auto fl = [](ll a, ll b) { return b; };
    auto fa = [](ll a, ll b) { return b; };
    auto fw = [](ll a, ll w) { return a; };
    SegmentTree<ll, ll> tree(n, fm, fl, fa, fw, LONG_MAX, LONG_MAX);
    return tree;
}

SegmentTree<ll, ll> RangeMaxTree(int n) {
    auto fm = [](ll a, ll b) { return max(a, b); };
    auto fl = [](ll a, ll b) { return b; };
    auto fa = [](ll a, ll b) { return b; };
    auto fw = [](ll a, ll w) { return a; };
    SegmentTree<ll, ll> tree(n, fm, fl, fa, fw, LONG_MIN, LONG_MIN);
    return tree;
}

SegmentTree<ll, ll> RangeSumTree(int n) {
    auto fm = [](ll a, ll b) { return a + b; };
    auto fl = [](ll a, ll b) { return a + b; };
    auto fa = [](ll a, ll b) { return a + b; };
    auto fw = [](ll a, ll w) { return a * w; };
    SegmentTree<ll, ll> tree(n, fm, fl, fa, fw, 0, 0);
    return tree;
}