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
template<typename Data, typename Lazy>
struct SegmentTree {
public:
    // mergeするときの操作
    using MergeData = function<Data(Data, Data)>;
    // lazyをxでupdate
    using UpdateLazyFromX = function<Lazy(Lazy, Lazy)>;
    // dataをlazyでupdate
    using UpdateDataFromLazy = function<Data(Data, Lazy)>;
    // lenが与えられた時にlazyを計算
    using CalcLazyWithLen = function<Lazy(Lazy, ll)>;

    // O(N)
    SegmentTree(int n, const MergeData fm, const UpdateLazyFromX fl, const UpdateDataFromLazy fa,
                const CalcLazyWithLen fw, Data M1, Lazy A1)
            : fm(fm), fl(fl), fa(fa), fw(fw), M1(M1), A1(A1) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.assign(2 * sz - 1, M1);
        lazy.assign(2 * sz - 1, A1);
    }

    void build(vector<Data> v) {
        rep(i, sz) seg[i + sz - 1] = v[i];
        for (ll i = sz - 2; i >= 0; --i) {
            seg[i] = fm(seg[i * 2 + 1], seg[i * 2 + 2]);
        }
    }

    // O(logN)
    Data update(int a, int b, Data x) {
        return update(a, b, x, 0, 0, sz);
    }

    // O(logN)
    Data query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }


    int sz;
    vector<Data> seg;
    vector<Lazy> lazy;

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
        eval(r - l, k);
        if (r <= a || b <= l) return M1;
        if (a <= l && r <= b) return seg[k];
        Data vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        Data vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
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