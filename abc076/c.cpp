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

string S, T;

void solve() {
    vector<int> ids;
    bool reached = false;
    int temp = 0;

    while (temp < S.length()) {
        int i_s = temp, i_t = 0, cnt = 0;
        while (i_t < T.length()) {
            if (S[i_s] == T[i_t] || S[i_s] == '?') {
                cnt++;
                if (cnt == T.length()) {
                    reached = true;
                    ids.emplace_back(temp);
                }
                i_s++, i_t++;
            } else {
                break;
            }
        }
        temp++;
    }
    if (reached) {
        vector<string> ans;
        EACH(t, ids) {
            string temp;
            REP(i, t) {
                if (S[i] == '?') temp += 'a';
                else temp += S[i];
            }
            REP(i, T.length()) {
                temp += T[i];
            }
            FOR(i, t + T.length(), S.length()) {
                if (S[i] == '?') temp += 'a';
                else temp += S[i];
            }
            ans.emplace_back(temp);
        }
        sort(ans.begin(), ans.end());
        cout << ans[0] << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
}

int main() {
    cin >> S >> T;
    solve();
    return 0;
}
