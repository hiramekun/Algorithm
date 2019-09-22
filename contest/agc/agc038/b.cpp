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

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

ll range_min_query(vl &tree, int qlow, int qhigh, int low, int high, int pos) {
    if (qlow <= low && qhigh >= high) return tree[pos];
    if (qlow > high || qhigh < low) return ll_inf;

    int mid = (low + high) / 2;
    return min(range_min_query(tree, qlow, qhigh, low, mid, 2 * pos + 1),
               range_min_query(tree, qlow, qhigh, mid, high, 2 * pos + 2));
}


void update(int a[], int st[], int i, int j, int idx, int val, int pos) {
    if (i == j) {
        a[idx] = val;
        st[pos] = val;
        printf("pos=%d\n", pos);
    } else {
        int mid = (i + j) / 2;
        if (i <= idx && idx <= mid) {
            update(a, st, i, mid, idx, val, 2 * pos + 1);
        } else {
            update(a, st, mid + 1, j, idx, val, 2 * pos + 2);
        }
        st[pos] = min(st[2 * pos + 1], st[2 * pos + 2]);
    }
}

void build_ST(vl &a, vl &st, int i, int j, int pos) {
    if (i == j) {
        st[pos] = a[i];
        return;
    }
    int mid = i + (j - i) / 2;
    build_ST(a, st, i, mid, 2 * pos + 1);
    build_ST(a, st, mid + 1, j, 2 * pos + 2);
    st[pos] = min(st[2 * pos + 1], st[2 * pos + 2]);
}

void build_MAX_ST(vl &a, vl &st, int i, int j, int pos) {
    if (i == j) {
        st[pos] = a[i];
        return;
    }
    int mid = i + (j - i) / 2;
    build_MAX_ST(a, st, i, mid, 2 * pos + 1);
    build_MAX_ST(a, st, mid + 1, j, 2 * pos + 2);
    st[pos] = max(st[2 * pos + 1], st[2 * pos + 2]);
}

int range_min_query(vl &st, int n, int i, int j, int qi, int qj, int pos) {
    if (qi < 0 || qj > n || qi > qj) {
        printf("Invalid Input");
        return -1;
    } else {
        if (qi <= i && qj >= j) {
            return st[pos];
        }
        if (j < qi || i > qj) {
            return INT_MAX;
        }
        int mid = i + (j - i) / 2;
        return min(range_min_query(st, n, i, mid, qi, qj, 2 * pos + 1),
                   range_min_query(st, n, mid + 1, j, qi, qj, 2 * pos + 2));
    }
}

int range_max_query(vl &st, int n, int i, int j, int qi, int qj, int pos) {
    if (qi < 0 || qj > n || qi > qj) {
        printf("Invalid Input");
        return -1;
    } else {
        if (qi <= i && qj >= j) {
            return st[pos];
        }
        if (j < qi || i > qj) {
            return INT_MIN;
        }
        int mid = i + (j - i) / 2;
        return max(range_max_query(st, n, i, mid, qi, qj, 2 * pos + 1),
                   range_max_query(st, n, mid + 1, j, qi, qj, 2 * pos + 2));
    }
}

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
    ll max_size = 2 * pow(2, ceil(log2(n))) - 1;
    vl minTree(max_size);
    vl maxTree(max_size);
    build_ST(p, minTree, 0, n - 1, 0);
    build_MAX_ST(p, maxTree, 0, n - 1, 0);

    ll prev_min = ll_inf, prev_max = ll_inf;
    ll ans = 0;
    rep(i, n - k + 1) {
        ll mi = range_min_query(minTree, n, 0, n - 1, i, i + k - 1, 0);
        ll mx = range_max_query(maxTree, n, 0, n - 1, i, i + k - 1, 0);
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
