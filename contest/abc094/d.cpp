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
int n, a[MAX_N];
int a_max = 0, a_medi = 0;

void solve() {
    int res = INF;
    int ans = 0;
    REP(i, n) {
        if (a[i] != a_max && res > abs(a_medi - a[i])) {
            ans = a[i];
            res = abs(a_medi - a[i]);
        }
    }
    printf("%d %d", a_max, ans);
}

int main() {
    cin >> n;
    REP(i, n) {
        cin >> a[i];
        a_max = max(a[i], a_max);
    }
    a_medi = a_max / 2;
    solve();
    return 0;
}
