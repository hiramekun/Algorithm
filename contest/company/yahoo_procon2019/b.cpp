#include <cstring>
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
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);


int main() {
    int a[3], b[3];
    int c[4];
    rep(i, 4) c[i] = 0;
    rep(i, 3) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        c[a[i]]++, c[b[i]]++;
    }
    int count1 = 0, count2 = 0;
    rep(i, 4) {
        if (c[i] == 1) count1++;
        if (c[i] == 2) count2++;
    }
    if (count1 == 2 && count2 == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
