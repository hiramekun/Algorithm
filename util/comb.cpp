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


void comb(int n, int k) {
    int arr[] = {1, 2, 3, 4}; // array must be sorted
    int com = (1 << k) - 1;
    while (com < 1 << n) {
        REP(j, n) if ((1 & com >> j) == 1) cout << arr[j] << endl;
        printf("\n");

        int x = com & -com, y = com + x;
        com = ((com & ~y) / x >> 1) | y;
    }
}

int main() {
    comb(4, 2);
    return 0;
}
