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

const int MAX_N = 500;
ll N, C[MAX_N], S[MAX_N], F[MAX_N];
ll t[MAX_N]; // t[i]:

void solve() {
    REP(i, N - 1) {
        fill(t, t + N, 0);
        FOR(j, i, N - 1) {
            if (j == i) {
                t[j + 1] = S[j] + C[j];
            } else {
                if (S[j] - t[j] > 0) {
                    t[j + 1] = t[j] + S[j] - t[j] + C[j];
                } else {
                    ll temp = (abs((S[j] - t[j])) % F[j]);
                    if (temp == 0) t[j + 1] = t[j] + C[j];
                    else t[j + 1] = t[j] + F[j] - temp + C[j];
                }
            }
        }
        cout << t[N - 1] << endl;
    }
    cout << 0 << endl;
}

int main() {
    cin >> N;
    REP(i, N - 1) cin >> C[i] >> S[i] >> F[i];
    solve();
    return 0;
}
