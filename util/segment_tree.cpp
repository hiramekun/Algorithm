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

void construct_tree(vl &input, vl &tree, int low, int high, int pos) {
    if (low == high) {
        tree[pos] = input[low];
        return;
    }
    int mid = (low + high) / 2;
    construct_tree(input, tree, low, mid, 2 * pos + 1);
    construct_tree(input, tree, mid, high, 2 * pos + 2);
    tree[pos] = min(tree[2 * pos + 1], tree[2 * pos + 2]);
}

ll range_min_query(vl &tree, int qlow, int qhigh, int low, int high, int pos) {
    if (qlow <= low && qhigh >= high) return tree[pos];
    if (qlow > high || qhigh < low) return ll_inf;

    int mid = (low + high) / 2;
    return min(range_min_query(tree, qlow, qhigh, low, mid, 2 * pos + 1),
               range_min_query(tree, qlow, qhigh, mid, high, 2 * pos + 2));
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif

#ifdef MY_DEBUG
    }
#endif
    return 0;
}