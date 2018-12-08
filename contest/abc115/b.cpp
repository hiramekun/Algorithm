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
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    int n, p[10];
    cin >> n;
    int maxp = 0;
    rep(i, n) {
        cin >> p[i];
        maxp = max(maxp, p[i]);
    }
    int ans = 0;
    bool devided = false;
    rep(i, n) {
        if (p[i] == maxp && !devided) {
            ans += (p[i] / 2);
            devided = true;
        } else ans += p[i];
    }
    cout << ans << endl;
    return 0;
}

