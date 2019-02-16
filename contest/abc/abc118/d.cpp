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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

const ll limit = ll(1e4);
ll n, m;
string dp[limit + 10];
ll w[] = {0,
          2,
          5,
          5,
          4,
          5,
          6,
          3,
          7,
          6};
vector<ll> a;

string max_s(string s1, string s2) {
    if (s1.size() == s2.size()) return s1 > s2 ? s1 : s2;
    else return s1.size() > s2.size() ? s1 : s2;
}


void solve() {

    dp[0] = ""; // i本使ってできる最大の数
    repone(i, n) dp[i] = "0";
    repone(i, n) {
        rep(j, m) {
            if (i >= w[a[j]]) {
                if (dp[i - w[a[j]]] == "0") continue;
                dp[i] = max_s(dp[i - w[a[j]]] + to_string(a[j]), dp[i]);
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    cin >> n >> m;
    a.resize(m);
    rep(i, m) {
        cin >> a[i];
    }
    solve();
    return 0;
}
