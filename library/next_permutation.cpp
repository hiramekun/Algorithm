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

const int MAX_N = 10;
int perm[MAX_N];
vector<int> perm2;
bool used[MAX_N];

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}

void print(const int v[], int n) {
    std::for_each(v, v + n, [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}

void permutation1(int pos, int n) {
    print(perm, n);
    if (pos == n) {
        return;
    }
    REP(i, n) {
        if (!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

void permutation2(int n) {
    REP(i, n) {
        perm2.emplace_back(i);
    }
    do {
        print(perm2);
    } while (next_permutation(perm2.begin(), perm2.end()));
    return;
}

int main() {
    permutation2(3);
    permutation1(0, 3);
    return 0;
}
