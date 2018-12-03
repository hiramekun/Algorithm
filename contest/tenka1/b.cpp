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

ll A, B;
int K;

void solve() {
    REP(i, K) {
        if (i % 2 == 0) {
            if (A % 2 == 0) {
                B += A / 2;
                A /= 2;
            } else {
                A -= 1;
                B += A / 2;
                A /= 2;
            }
        } else {
            if (B % 2 == 0) {
                A += B / 2;
                B /= 2;
            } else {
                B -= 1;
                A += B / 2;
                B /= 2;
            }
        }
    }
    printf("%lli %lli", A, B);
}

int main() {
    cin >> A >> B >> K;
    solve();
    return 0;
}
