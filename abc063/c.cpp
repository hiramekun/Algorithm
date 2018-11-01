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

const int MAX_N = 100;
int N, s[MAX_N];

void solve() {
    sort(s, s + N, greater<>());
    int sum = 0;
    REP(i, N) sum += s[i];
    if (sum % 10 == 0) {
        REPR(i, N) {
            if (s[i] % 10 != 0) {
                sum -= s[i];
                cout << sum << endl;
                return;
            }
        }
        cout << 0 << endl;
    } else {
        cout << sum << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> s[i];
    solve();
    return 0;
}
