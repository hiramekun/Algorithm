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
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)


void solve() {
    const int n = 3;
    int sample[n] = {1, 2, 3};
    REP(i, pow(2, n)) {
        int sum = 0;
        REP(j, n) if ((1 & i >> j) == 1) sum += sample[j];
        cout << sum << endl;
    }
}

int main() {
    solve();
    return 0;
}

