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

void solve() {
    unordered_map<int, int> mp_even, mp_odd;
    vector<pair<int, int> >
            elem_even(mp_even.begin(), mp_even.end()),
            elem_odd(mp_odd.begin(), mp_odd.end());
    sort(elem_even.begin(), elem_even.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });
    sort(elem_odd.begin(), elem_odd.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

    if (elem_even[0].first != elem_odd[0].first) {
        cout << n - elem_even[0].second - elem_odd[0].second << endl;
    } else {
        cout << min(n - elem_even[1].second - elem_odd[0].second,
                    n - elem_even[0].second - elem_odd[1].second) << endl;
    }
}

int main() {
    cin >> n;
    int temp;
    REP(i, n) {
        cin >> temp;
        if (i % 2 == 0) mp_even[temp]++;
        else mp_odd[temp]++;
    }
    solve();
    return 0;
}
