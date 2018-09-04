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


int N;

bool is_prime(int p) {
    if (p == 1) return false;
    FOR(i, 2, p) if (p % i == 0)return false;
    return true;
}

void solve() {
    vector<int> primes;
    FOR(i, 2, 55555) {
        if (is_prime(i)) primes.push_back(i);
    }
    int count = 0;
    EACH(p, primes) {
        if (p % 5 == 1) {
            count++;
            cout << p << ' ';
        }
        if (count == N) break;
    }
}

int main() {
    cin >> N;
    solve();
    return 0;
}

