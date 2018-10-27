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
map<ll, ll, greater<> > mp;

void solve() {
    ll big = -1;
    ll ans = 0;
    EACH(m, mp) {
        if (big == -1 && m.second >= 4) {
            ans = m.first * m.first;
            break;
        }
        if (m.second >= 2) {
            if (big == -1) big = m.first;
            else {
                ans = big * m.first;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    int temp;
    REP(i, N) {
        cin >> temp;
        mp[temp]++;
    }
    solve();
    return 0;
}
