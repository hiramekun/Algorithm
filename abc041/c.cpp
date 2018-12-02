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


int N;
unordered_map<ll, ll> mp;

void solve() {
    vector<pair<ll, ll> > v(mp.begin(), mp.end());
    // sort from bigger.
    sort(v.begin(), v.end(),
         [](pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; });
    each(i, v) cout << i.first << endl;
}

int main() {
    cin >> N;
    int temp;
    repone(i, N) {
        cin >> temp;
        mp[i] = temp;
    }
    solve();
    return 0;
}
