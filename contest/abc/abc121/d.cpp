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
#include <bitset>

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

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif

        ll a, b;
        cin >> a >> b;
        bitset<48> bita(a), bitb(b);
        int bi = 0;
        int ai = 0;

        ll c[48];
        fill(c, c + 48, 0);

        rep(i, 48) {
            if (bitb[i] == 1) {
                bi = i;
                c[i]++;
            }
            if (bita[i] == 1) {
                ai = i;
                c[i]++;
            }
        }
        c[ai]--, c[bi]--;
        rep(i, bi) c[i] += ll(pow(2, bi));
        rep(i, ai) c[i] += ll(pow(2, ai));
        bitset<48> ans;
        rep(i, 48) {
            if (c[i] != 0 && c[i] % 2 == 0) ans[i] = true;
            else ans[i] = false;
        }

        cout << ans.to_ullong() << endl;


#ifdef MY_DEBUG
    }
#endif
    return 0;
}