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
#define INF int(1e9)
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = int(1e5);
ll N, A[MAX_N];

void solve() {
    bool is_inc = false, is_dec = false;
    ll before = -1, sep = 0;
    REP(i, N) {
        if (before == -1) {
        } else if (A[i] > before) {
            if (is_dec) {
                is_dec = false;
                sep++;
            } else {
                is_inc = true;
            }
        } else if (A[i] < before) {
            if (is_inc) {
                is_inc = false;
                sep++;;
            } else {
                is_dec = true;
            }
        }
        before = A[i];
    }
    cout << sep + 1 << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    solve();
    return 0;
}
