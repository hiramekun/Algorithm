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

int abcd[4];
int temp;

void dfs() {
    const int n = 4;
    REP(i, 1 << n) {
        int sum = 0;
        string ops;

        REP(j, n) {
            if ((i & (1 << j))) {
                sum += abcd[j];
                ops += '+';
            } else {
                sum -= abcd[j];
                ops += '-';
            }
        }
        if (sum == 7) {
            cout << to_string(abcd[0]) + ops[1] + to_string(abcd[1]) + ops[2] + to_string(abcd[2]) +
                    ops[3] + to_string(abcd[3]) + "=7" << endl;
            return;
        }
    }
}

void solve() {
    dfs();
}

int main() {
    cin >> temp;
    abcd[0] = temp / 1000;
    abcd[1] = (temp - abcd[0] * 1000) / 100;
    abcd[2] = (temp - abcd[0] * 1000 - abcd[1] * 100) / 10;
    abcd[3] = (temp - abcd[0] * 1000 - abcd[1] * 100 - abcd[2] * 10) / 1;
    solve();
    return 0;
}
