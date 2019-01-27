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

string S;

void solve() {
    unordered_map<char, int> mp;
    mp['a'] = 0, mp['b'] = 0, mp['c'] = 0;
    rep(i, S.length()) {
        mp[S[i]]++;
    }
    int i_max = 0, i_min = i_inf;
    each(i, mp) {
        i_max = max(i.second, i_max);
        i_min = min(i.second, i_min);
    }
    if (abs(i_max - i_min) <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin >> S;
    solve();
    return 0;
}
