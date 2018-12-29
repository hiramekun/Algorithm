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
#define INF int(1e9)
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define REPONE(i, n) for(int i = 1; i <= (int)(n); i++)
#define EACH(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)


int A, B;

void solve() {
    int ans = 0;
    int nums[5];
    FOR(i, A, B + 1) {
        int temp = i;
        REP(j, 5) {
            nums[j] = temp % 10;
            temp /= 10;
        }
        REP(j, 5) {
            if (nums[j] != nums[4 - j]) break;
            if (j == 4) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> A >> B;
    solve();
    return 0;
}
