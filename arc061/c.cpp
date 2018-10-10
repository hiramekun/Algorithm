#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)

ll S, s_len = 0;
ll s_num[10];

void solve() {
    ll ans = 0;
    for (ll i = 0; i < pow(2, s_len); i++) {
        ll sum = 0;
        string temp;
        for (ll j = 0; j < s_len; j++) {
            if (1 & i >> (s_len - 1) != 1) continue;
            temp += to_string(s_num[s_len - 1 - j]);
            if ((1 & i >> j) == 1) {
                sum += stol(temp);
                temp = "";
            }
        }
        ans += sum;
    }
    cout << ans << endl;
}

int main() {
    cin >> S;
    while (S > 0) {
        s_num[s_len++] = S % 10;
        S /= 10;
    }
    solve();
    return 0;
}
