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
typedef pair<ll, ll> P;
typedef vector<ll> vll;

template<class T = ll>
T in() {
    T x;
    cin >> x;
    return (x);
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        vll a(x), b(y), c(z);
        rep(i, x) a[i] = in();
        rep(i, y) b[i] = in();
        rep(i, z) c[i] = in();

        vll ab;
        rep(i, x) rep(j, y) ab.eb(a[i] + b[j]);
        sort(all(ab), greater<>());
        priority_queue<ll, vector<ll>, greater<>> que;

        rep(i, min(x * y, k)) {
            rep(j, z) {
                if (que.size() < k) que.push(ab[i] + c[j]);
                else if (que.top() < ab[i] + c[j]) {
                    que.pop();
                    que.push(ab[i] + c[j]);
                }
            }
        }

        vll ans(k);
        rep(i, k) {
            ans[k - i - 1] = que.top();
            que.pop();
        }
        rep(i, k) printf("%lli\n", ans[i]);


#ifdef MY_DEBUG
    }
#endif
    return 0;
}