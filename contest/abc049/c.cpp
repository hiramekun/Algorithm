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

string S;

void solve() {
    string dream = "dream", dreamer = "dreamer", erase = "erase", eraser = "eraser";
    reverse(dream.begin(), dream.end());
    reverse(dreamer.begin(), dreamer.end());
    reverse(erase.begin(), erase.end());
    reverse(eraser.begin(), eraser.end());
    int idx = 0;
    string T;
    while (idx < S.length()) {
        if (S[idx] == 'r') {
            if (S[idx + 2] == 's') {
                REP(i, 6) {
                    if (eraser[i] != S[idx + i]) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                idx += 6;
            } else {
                REP(i, 7) {
                    if (dreamer[i] != S[idx + i]) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                idx += 7;
            }

        } else if (S[idx] == 'e') {
            REP(i, 5) {
                if (erase[i] != S[idx + i]) {
                    cout << "NO" << endl;
                    return;
                }
            }
            idx += 5;

        } else if (S[idx] == 'm') {
            REP(i, 5) {
                if (dream[i] != S[idx + i]) {
                    cout << "NO" << endl;
                    return;
                }
            }
            idx += 5;

        } else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    cin >> S;
    reverse(S.begin(), S.end());
    solve();
    return 0;
}
