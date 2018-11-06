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
typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N;

vector<int> each_digit(ll S) {
    int n_len = 0, n_dig[16];
    while (S > 0) {
        n_dig[n_len++] = S % 10;
        S /= 10;
    }
    vector<int> ret(n_dig, n_dig + n_len);
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve() {
    vector<int> dig = each_digit(N);
    int max_dig = -1, second_dig = -1;
    REP(i, dig.size()) {
        if (dig[i] != 9) {
            if (max_dig == -1) max_dig = i;
            else if (second_dig == -1) second_dig = i;
        }
    }
    int ans = 0;
    if (dig.size() == 1) ans = dig[0];
    else if (max_dig == -1) {
        REP(i, dig.size()) ans += 9;
    } else if (max_dig == 0) {
        if (second_dig == -1) {
            REP(i, dig.size()) ans += dig[i];
        } else {
            REP(i, dig.size()) {
                if (i == 0)ans += dig[0] - 1;
                else ans += 9;
            }
        }
    } else {
        REP(i, dig.size()) {
            if (i == max_dig - 1) ans += dig[i] - 1;
            else if (i < max_dig) ans += dig[i];
            else ans += 9;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    solve();
    return 0;
}
