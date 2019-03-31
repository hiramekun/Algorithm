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
#include <numeric>
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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif

        ll n, q;
        string s;
        cin >> n >> q >> s;
        char t[q], d[q];
        rep(i, q) cin >> t[i] >> d[i];

        // solve
        ll il = 0, ir = n - 1;
        repr(i, q) {
            if (il < n && t[i] == s[il] && d[i] == 'L') il++;
            if (il > 0 && t[i] == s[il - 1] && d[i] == 'R') il--;
            if (ir >= 0 && t[i] == s[ir] && d[i] == 'R') ir--;
            if (il < n - 1 && t[i] == s[ir + 1] && d[i] == 'L') ir++;
        }
        cout << max(0LL, ir - il + 1) << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}