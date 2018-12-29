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


void solve() {
}

int main() {
    int abc[3], K;
    int max_num = -1, max_idx = 0;
    REP(i, 3) {
        cin >> abc[i];
        if (max_num < abc[i]) {
            max_idx = i;
            max_num = abc[i];
        }
    }
    cin >> K;
    int ans = 0;
    REP(i, 3) {
        if (i == max_idx) ans += max_num * (int) pow(2, K);
        else ans += abc[i];
    }
    cout << ans << endl;
    return 0;
}

