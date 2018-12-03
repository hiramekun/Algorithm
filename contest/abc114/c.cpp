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


ll N;

vector<ll> each_digit(ll S) {
    ll n_len = 0, n_dig[9];
    while (S > 0) {
        n_dig[n_len++] = S % 10;
        S /= 10;
    }
    vector<ll> ret(n_dig, n_dig + n_len);
    return ret;
}

ll ans = 0;

void dfs(int s_len, string now, string next, bool three, bool five, bool seven) {
    string s_next = now + next;

    if (three && five && seven && s_next.size() == s_len && stoi(s_next) <= N) {
        ans++;
        return;
    } else if (s_next.size() == s_len) return;

    dfs(s_len, s_next, "3", true, five, seven);
    dfs(s_len, s_next, "5", three, true, seven);
    dfs(s_len, s_next, "7", three, five, true);
}

void solve() {
    ll rank = each_digit(N).size();
    repone(i, rank) {
        dfs(i, "", "3", true, false, false);
        dfs(i, "", "5", false, true, false);
        dfs(i, "", "7", false, false, true);
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    solve();
    return 0;
}
