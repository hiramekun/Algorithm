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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef pair<ll, ll> P;
typedef vector<ll> vll;

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
        ll tmp;
        rep(i, x) {
            scanf("%lli", &tmp);
            a[i] = tmp;
        }
        rep(i, y) {
            scanf("%lli", &tmp);
            b[i] = tmp;
        }
        rep(i, z) {
            scanf("%lli", &tmp);
            c[i] = tmp;
        }

        priority_queue<ll, vector<ll>, greater<>> que;
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        sort(c.begin(), c.end(), greater<>());

        rep(i, x) {
            rep(j, y) {
                rep(l, z) {
                    if (que.size() < k) que.push(a[i] + b[j] + c[l]);
                    else if (a[i] + b[j] + c[l] > que.top()) {
                        que.pop();
                        que.push(a[i] + b[j] + c[l]);
                    }
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