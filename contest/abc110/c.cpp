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

string S, T;
map<char, int> mpS;
map<char, int> mpT;

void solve() {
    REP(i, S.length()) {
        mpS[S[i]]++;
        mpT[T[i]]++;
    }
    REP(i, S.length()) {
        if (mpS[S[i]] != mpT[S[i]] && mpS[S[i]] != mpT[T[i]]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin >> S >> T;
    solve();
    return 0;
}
