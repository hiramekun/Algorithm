#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> P;

ump mp;

void solve() {
}

string a, b, c;

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif

        cin >> a >> b >> c;
        char next = 'a';
        int ia = 0, ib = 0, ic = 0;
        while (true) {
            if (next == 'a') {
                if (ia == a.size()) {
                    cout << "A" << endl;
                    return 0;
                }

                next = a[ia];
                ia++;
            } else if (next == 'b') {
                if (ib == b.size()) {
                    cout << "B" << endl;
                    return 0;
                }

                next = b[ib];
                ib++;
            } else {
                if (ic == c.size()) {
                    cout << "C" << endl;
                    return 0;
                }

                next = c[ic];
                ic++;
            }
        }
        solve();

#ifdef MY_DEBUG
    }
#endif
    return 0;
}