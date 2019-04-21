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

struct sel {
    ll s, e, l;
};

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll t = inl();
        rep(tc, t) {
            ll n = inl(), s = inl();
            vl a(n);
            mpll mp;
            ll idx = 0;
            rep(i, n) {
                a[i] = inl();
                if (mp[a[i]] == 0) {
                    idx++;
                }
                mp[a[i]]++;
            }


            ll ans = 0;
            ll right = 0;
            mpll mp2;
            set<ll> set1;
            for (ll left = 0; left < n; ++left) {
                mp2[a[right]]++;
                if (mp2[a[right]] <= s) {
                    set1.insert(a[right]);

                    while (right + 1 < n && mp2[a[right + 1]] <= s) {
                        ++right;
                        mp2[a[right]]++;
                        set1.insert(a[right]);
                    }
                } else set1.erase(a[right]);



                /* break した状態で right は条件を満たす最大なので、何かする */
                // res += (right - left);
                ans = max(ans, ll(set1.size()));

                /* left をインクリメントする準備 */
                if (right == left) ++right;
                else {
                    mp2[a[left]]--;
                    if (mp2[a[left]] && mp2[a[left]] <= s) set1.insert(a[left]);
                }
            }

            cout << "Case #" << tc + 1 << ": " << ans << endl;
        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}
