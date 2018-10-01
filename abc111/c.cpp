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
int n;
int times_odd[MAX_N + 1];
int times_even[MAX_N + 1];

void solve() {
    int max_odd = 0, second_odd = 0, max_odd_num = 0;
    int max_even = 0, second_even = 0, max_even_num = 0;
    REP(i, MAX_N + 1) {
        if (max_even <= times_even[i]) {
            max_even_num = i;
            second_even = max_even, max_even = times_even[i];
        } else if (second_even < times_even[i]) {
            second_even = times_even[i];
        }
        if (max_odd <= times_odd[i]) {
            max_odd_num = i;
            second_odd = max_odd, max_odd = times_odd[i];
        } else if (second_odd < times_odd[i]) {
            second_odd = times_odd[i];
        }
    }


    if (max_odd_num == max_even_num) {
        if (second_odd > second_even) {
            cout << n / 2 - second_odd + n / 2 - max_even << endl;
        } else {
            cout << n / 2 - second_even + n / 2 - max_odd << endl;
        }
    } else {
        cout << n / 2 - max_odd + n / 2 - max_even << endl;
    }
}

int main() {
    cin >> n;
    int temp;
    REP(i, n) {
        cin >> temp;
        if (i % 2 == 0) times_even[temp]++;
        else times_odd[temp]++;
    }
    solve();
    return 0;
}
