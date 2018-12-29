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

const int MAX_N = 50;
int n;
vector<string> S;
vector<map<char, int> > v;


void solve() {
    EACH(m, v[0]) {
        int temp = INF;
        REP(j, n) {
            temp = min(v[j][m.first], temp);
        }
        REP(k, temp) cout << m.first;
    }
}

int main() {
    cin >> n;
    string temp;
    REP(i, n) {
        cin >> temp;
        S.emplace_back(temp);
        map<char, int> mp = {
                {'a', 0},
                {'b', 0},
                {'c', 0},
                {'d', 0},
                {'e', 0},
                {'f', 0},
                {'g', 0},
                {'h', 0},
                {'i', 0},
                {'j', 0},
                {'k', 0},
                {'l', 0},
                {'m', 0},
                {'n', 0},
                {'o', 0},
                {'p', 0},
                {'q', 0},
                {'r', 0},
                {'s', 0},
                {'t', 0},
                {'u', 0},
                {'v', 0},
                {'w', 0},
                {'x', 0},
                {'y', 0},
                {'z', 0}
        };
        REP(j, temp.length()) mp[temp[j]]++;
        v.emplace_back(mp);
    }
    solve();
    return 0;
}
