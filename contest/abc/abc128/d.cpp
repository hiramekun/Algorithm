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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n = inl(), k = inl();
        vl v(n);
        rep(i, n) cin >> v[i];

        ll ans = 0;
        rep(i, k + 1) {
            ll tmp = 0;

            for (ll s = 0; s <= k; s++) {
                for (ll j = min(n - 1, s - 1 - i); j >= 0; --j) {
                    minPQ<ll> pq;
                    for (ll l = 0; l <= j; l++) {
                        pq.push(v[l]);
                    }
                    ll res = min(n - 1, s - 1 - i) - j - 1;
                    for (ll l = 0; l <= res; l++) {
                        pq.push(v[n - 1 - l]);
                    }

                    ll tmp2 = 0;
                    ll c = i;
                    while (!pq.empty()) {
                        if (c) pq.pop(), c--;
                        else {
                            tmp2 += pq.top();
                            pq.pop();
                        }
                    }
                    tmp = max(tmp2, tmp);
                }
            }
            ans = max(tmp, ans);
        }
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}