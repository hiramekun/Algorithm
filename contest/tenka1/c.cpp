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

const int MAX_N = int(1e5);
int N;
ll a[MAX_N];
vector<ll> v;

void solve() {
    sort(v.begin(), v.end());
    ll ans[2][N];

    int center = 0;
    if (N % 2 == 0) center = N / 2 - 1;
    else center = N / 2;

    REP(k, 2) {
        bool is_small = k % 2 == 0;
        int small = 0, big = static_cast<int>(v.size() - 1);
        REP(i, N / 2 + 1) {
            if (is_small) {
                if (center + i < N) ans[k][center + i] = v[small++];
                if (i != 0 && center - i >= 0) ans[k][center - i] = v[small++];
            } else {
                if (center + i < N) ans[k][center + i] = v[big--];
                if (i != 0 && center - i >= 0) ans[k][center - i] = v[big--];
            }
            is_small = !is_small;
        }
    }
    ll ret = 0;
    REP(k, 2) {
        ll n = 0;
        REP(i, N - 1) n += abs(ans[k][i] - ans[k][i + 1]);
        ret = max(n, ret);
    }
    cout << ret << endl;
}

int main() {
    cin >> N;
    ll temp;
    REP(i, N) {
        cin >> temp;
        v.emplace_back(temp);
    }
    solve();
    return 0;
}
