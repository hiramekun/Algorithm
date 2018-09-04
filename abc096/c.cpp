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

const int MAX_H = 50;
char s[MAX_H][MAX_H];
int H, W;

void solve() {
    REP(h, H) REP(w, W) {
            if (s[h][w] == '.') continue;
            if (s[max(h - 1, 0)][w] != '#' && s[min(h + 1, H - 1)][w] != '#' &&
                s[h][max(w - 1, 0)] != '#' && s[h][min(w + 1, W - 1)] != '#') {
                cout << "No" << endl;
                return;
            }
        }
    cout << "Yes" << endl;
}

int main() {
    cin >> H >> W;
    REP(h, H) REP(w, W) cin >> s[h][w];
    solve();
    return 0;
}
