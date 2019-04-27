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
        ll n = inl();
        vl s(n);
        rep(i, n) cin >> s[i];
        ll l = 0, r = n - 1;
        string ans;
        vl now;
        while (l <= r) {
            if (s[l] == s[r]) {
                ll cl = 0;
                if (now.empty() || s[l] > now.back()) {
                    cl++;
                    while (l + 1 <= n - 1 && s[l + 1] > s[l]) {
                        l++;
                        cl++;
                    }
                }
                ll cr = 0;
                if (now.empty() || s[r] > now.back()) {
                    cr++;
                    while (r - 1 >= 0 && s[r - 1] > s[r]) {
                        r--;
                        cr++;
                    }
                }
                if (cl > cr) {
                    for (int i = 0; i < cl; ++i) {
                        ans += 'L';
                    }
                } else {
                    for (int i = 0; i < cr; ++i) {
                        ans += 'R';
                    }
                }
                break;
            }
            if ((now.empty() || s[l] > now.back()) && s[l] < s[r]) {
                ans += 'L';
                now.eb(s[l]);
                l++;
            } else if (now.empty() || s[r] > now.back()) {
                ans += 'R';
                now.eb(s[r]);
                r--;
            } else if (now.empty() || s[l] > now.back()) {
                ans += 'L';
                now.eb(s[l]);
                l++;
            } else break;
        }
        cout << ans.size() << endl;
        cout << ans << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}