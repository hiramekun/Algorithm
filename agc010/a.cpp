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

int N;
const int MAX_N = int(1e5);
ll A[MAX_N];

int main() {
    cin >> N;
    int n_odd = 0, n_even = 0;
    REP(i, N) {
        cin >> A[i];
        if (A[i] % 2 == 0) n_even++;
        else n_odd++;
    }
    if (n_odd % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}