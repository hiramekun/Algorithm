#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)


const int MAX_N = (int) 1e5;
int N, X, x[MAX_N];
int diffs[MAX_N];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int pregcd = 1;
    REP(i, N) pregcd = i == 0 ? diffs[0] : gcd(diffs[i], pregcd);
    cout << pregcd << endl;
}

int main() {
    cin >> N >> X;
    REP(i, N) {
        cin >> x[i];
        diffs[i] = abs(X - x[i]);
    }
    solve();
    return 0;
}
