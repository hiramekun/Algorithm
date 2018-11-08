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
#define REPONE(i, n) for(ll i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll N;
int MAX_N = 10;

// 1234 -> 4 3 2 1
vector<int> each_digit(ll S) {
    int n_len = 0, n_dig[MAX_N];
    while (S > 0) {
        n_dig[n_len++] = S % 10;
        S /= 10;
    }
    vector<int> ret(n_dig, n_dig + n_len);
    return ret;
}

void solve() {
    ll ans = INF;
    int n_dig = each_digit(N).size();
    REPONE(i, pow(10, 6)) {
        if (N % i == 0) ans = min(ans, max(i, N / i));
    }
    vector<int> v = each_digit(ans);
    cout << v.size() << endl;
}

int main() {
    cin >> N;
    solve();
    return 0;
}
