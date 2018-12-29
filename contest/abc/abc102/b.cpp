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

const int MAX_N = 100;
int N, A[MAX_N];

void solve() {
}

int main() {
    cin >> N;
    int a = 0, b = INF, temp;
    REP(i, N) {
        cin >> temp;
        a = max(temp, a);
        b = min(temp, b);
    }
    cout << a - b << endl;
    solve();
    return 0;
}

