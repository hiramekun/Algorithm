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


int n;
vector<int> a;

void solve() {
    unordered_map<int, int> mp;
    rep(i, n) mp[a[i]]++;
    vector<pair<ll, ll> > v(mp.begin(), mp.end());
    // sort from bigger.
    sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; });
    vector<int> only_one;
    stack<int> twos;
    each(i, v) {
        if (i.second == 1) only_one.emplace_back(i.first);
        else if (i.second % 2 != 0) only_one.emplace_back(i.first);
        else if (i.second % 2 == 0) twos.push(i.first);
    }
    while (twos.size() >= 2) {
        only_one.emplace_back(twos.top());
        twos.pop();
        only_one.emplace_back(twos.top());
        twos.pop();
    }
    cout << only_one.size() << endl;
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i, n)cin >> a[i];
    solve();
    return 0;
}
