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
//typedef pair<int, int> P;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll Q, H, S, D, N;
vector<pair<ll, double> > v1, v2;
typedef pair<ll, double> P;

void solve() {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll ans;
    if (N % 2 == 0) {
        ans += N / 2 * v1[0].first;
    } else {
        ans += (N - 1) / 2 * v1[0].first;
        ans += v2[0].first;
    }
    cout << ans << endl;
}

int main() {
    cin >> Q >> H >> S >> D >> N;
    v1.emplace_back(P(Q * 8, 0.25));
    v1.emplace_back(P(H * 4, 0.5));
    v1.emplace_back(P(S * 2, 1));
    v1.emplace_back(P(D, 2));

    v2.emplace_back(P(Q * 4, 0.25));
    v2.emplace_back(P(H * 2, 0.5));
    v2.emplace_back(P(S * 1, 1));
    solve();
    return 0;
}
