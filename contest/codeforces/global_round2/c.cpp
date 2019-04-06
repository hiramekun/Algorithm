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
        ll n, m;
        cin >> n >> m;
        int a[n][m], b[n][m];
        rep(i, n) rep(j, m) {
                cin >> a[i][j];
            }
        rep(i, n) rep(j, m) {
                cin >> b[i][j];
            }

        rep(i, n) {
            ll idx1 = inf, idx2 = inf;
            ll c = 0;
            rep(j, m) {
                if (a[i][j] != b[i][j]) {
                    if (c == 0) idx1 = j;
                    if (c == 1) idx2 = j;
                    c++;
                }
                if (c == 2) {
                    ll tmp1 = 0, tmp2 = 0;
                    rep(k, n) {
                        if (a[k][idx1] != b[k][idx1]) {
                            tmp1++;
                        }
                        if (a[k][idx2] != b[k][idx2]) {
                            tmp2++;
                        }
                    }
                    if (tmp1 % 2 != 0 || tmp2 % 2 != 0) {
                        cout << "No" << endl;
                        return 0;
                    }
                    c = 0;
                }
                if (c == 1 && j == m - 1) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        cout << "Yes" << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}