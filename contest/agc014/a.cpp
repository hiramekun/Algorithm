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


ll A, B, C;

void solve() {
    int powab = 0;
    ll ab = A + B;
    while (ab % 2 == 0) {
        ab /= 2;
        powab++;
    }
    ll bc = B + C;
    int powbc = 0;
    while (bc % 2 == 0) {
        bc /= 2;
        powbc++;
    }
    ll ca = C + A;
    int powca = 0;
    while (ca % 2 == 0) {
        ca /= 2;
        powca++;
    }
    if (A % 2 != 0 || B % 2 != 0 || C % 2 != 0) cout << 0 << endl;
    else if (A == B && B == C) cout << -1 << endl;
    else cout << min(powca, min(powab, powbc)) << endl;
}

int main() {
    cin >> A >> B >> C;
    solve();
    return 0;
}
