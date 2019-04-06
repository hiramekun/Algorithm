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
        ll n, h;
        cin >> n >> h;
        vll a(n);
        rep(i, n) cin >> a[i];

        vll ap;
        for (int i = 0; i < n; i++) {
            ap.eb(a[i]);
            sort(ap.begin(), ap.end(), greater<>());
            ll tmp = 0;
            for (int j = 0; j < ap.size(); j += 2) {
                tmp += ap[j];
            }
            if (tmp > h) {
                cout << i << endl;
                break;
            }
            if (i == n - 1) {
                cout << i + 1 << endl;
            }
        }


#ifdef MY_DEBUG
    }
#endif
    return 0;
}