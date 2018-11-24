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
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    int N, a[100];
    cin >> N;
    double sum = 0;
    REP(i, N) {
        cin >> a[i];
        sum += a[i];
    }
    double a_mean = sum / N;
    int ans = INF;
    double min_ans = INF;
    REP(i, N) {
        if (abs(a_mean - a[i]) < min_ans) {
            ans = i;
            min_ans = abs(a_mean - a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
