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

const int MAX_N = int(1e5);
int N;
string S[MAX_N];
unordered_map<char, ll> mp;

void solve() {
    ll ans = 0;
    EACH(i, mp) {
        EACH(j, mp) {
            EACH(k, mp) {
                if (i.first == j.first || j.first == k.first || k.first == i.first) continue;
                ans += i.second * j.second * k.second;
            }
        }
    }
    cout << ans / 6 << endl;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> S[i];
        if (S[i][0] == 'M' || S[i][0] == 'A' || S[i][0] == 'R' || S[i][0] == 'C' ||
            S[i][0] == 'H') {
            mp[S[i][0]]++;
        }
    }
    solve();
    return 0;
}
