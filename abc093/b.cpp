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

int A, B, K;

void solve() {
    REP(j, K) {
        if ((B - A) / 2 >= j) cout << A + j << endl;
    }
    REPR(j, K) {
        if ((B - A) % 2 != 0 && (B - A) / 2 >= j) cout << B - j << endl;
        if ((B - A) % 2 == 0 && (B - A) / 2 > j) cout << B - j << endl;
    }
}

int main() {
    cin >> A >> B >> K;
    solve();
    return 0;
}
