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

const int MAX_N = 200000;
int N, X_copy[MAX_N];
vector<int> X;

void solve() {
    sort(X.begin(), X.end());
    REP(i, N) {
        if (X_copy[i] <= X[(N - 1) / 2]) cout << X[N / 2] << endl;
        else cout << X[(N - 1) / 2] << endl;
    }
}

int main() {
    cin >> N;
    int temp = 0;
    REP(i, N) {
        cin >> temp;
        X.emplace_back(temp);
        X_copy[i] = temp;
    }
    solve();
    return 0;
}
