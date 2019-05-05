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

ll h, w, n, sr, sc;

void swich_by_val(bool isT, char val, ll &l, ll &r, ll &u, ll &d) {
    switch (val) {
        case 'L':
            if (isT) l++;
            else r = min(w - 1, r + 1);
            break;
        case 'R':
            if (isT) r--;
            else l = max(0LL, l - 1);
            break;
        case 'U':
            if (isT) u++;
            else d = min(h - 1, d + 1);
            break;
        case 'D':
            if (isT) d--;
            else u = max(0LL, u - 1);
            break;
    }
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        string s, t;
        cin >> h >> w >> n >> sr >> sc;
        cin >> s >> t;
        sr--, sc--;

        ll l = 0, r = w - 1, u = 0, d = h - 1;
        repr(i, s.size()) {
            char aoki = t[i];
            swich_by_val(false, aoki, l, r, u, d);
            char taka = s[i];
            swich_by_val(true, taka, l, r, u, d);

            if (r < l || d < u) {
                break;
            }
        }
        if (l <= sc && sc <= r && u <= sr && sr <= d) cout << "YES" << endl;
        else cout << "NO" << endl;


#ifdef MY_DEBUG
    }

#endif
    return 0;
}