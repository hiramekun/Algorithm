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

const int MAX_N = 10;
int n, k, c[MAX_N];

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}

void solve() {
    int com = (1 << k) - 1;
    unordered_map<string, bool> mp;

    int ans = 0;
    while (com < 1 << n) {
        vector<int> v_num;
        REP(j, n) {
            if ((1 & com >> j) == 1) v_num.emplace_back(c[j]);
        }
        sort(v_num.begin(), v_num.end());

        do {
            string temp;
            EACH(v, v_num) temp += to_string(v);
            if (!mp[temp]) {
                mp[temp] = true;
                ans++;
            }
        } while (next_permutation(v_num.begin(), v_num.end()));

        int x = com & -com, y = com + x;
        com = ((com & ~y) / x >> 1) | y;
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> k;
    REP(i, n) cin >> c[i];
    solve();
    return 0;
}
