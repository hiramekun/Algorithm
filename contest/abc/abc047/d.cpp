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


ll N, T;
vector<ll> A;

void solve() {
    ll temp_min = ll_inf;
    vector<ll> mina;
    rep(i, N) {
        temp_min = min(temp_min, A[i]);
        mina.emplace_back(temp_min);
    }
    vector<ll> diffa;
    rep(i, N) diffa.emplace_back(A[i] - mina[i]);
    ll maxd = *max_element(diffa.begin(), diffa.end());

    ll ans = 0;
    ll cur_min = -1;
    ll i = 0;
    while (i < N) {
        if (A[i] != cur_min && diffa[i] == 0) {
            cur_min = A[i];
        } else if (A[i] - cur_min == maxd) {
            ans++;
        }
        i++;
    }
    cout << ans << endl;
}

int main() {
    cin >> N >> T;
    A.resize(N);
    rep(i, N) cin >> A[i];
    solve();
    return 0;
}
