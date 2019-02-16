#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

const int limit = 100;
int h, w;
char a[limit][limit];
unordered_map<int, int> mp, mp_mod;

void solve() {
    if (mp_mod[3] > 1) {
        cout << "No" << endl;
        return;
    } else if (mp_mod[3] == 1) {
        mp_mod[1]++, mp_mod[2]++, mp_mod[3]--;
    }
    if (h % 2 == 1 && w % 2 == 1) {
        if (mp_mod[1] == 1) {
            if (mp_mod[2] * 2 <= h - 1 + w - 1 && (h - 1 + w - 1 - mp_mod[2] * 2) % 4 == 0) {
                cout << "Yes" << endl;
                return;
            }
        }
    } else if (w % 2 == 1) {
        if (mp_mod[1] == 0) {
            if (mp_mod[2] * 2 <= h && (h - mp_mod[2] * 2) % 4 == 0) {
                cout << "Yes" << endl;
                return;
            }
        }
    } else if (h % 2 == 1) {
        if (mp_mod[1] == 0) {
            if (mp_mod[2] * 2 <= w && (w - mp_mod[2] * 2) % 4 == 0) {
                cout << "Yes" << endl;
                return;
            }
        }
    } else {
        if (mp_mod[1] == 0 && mp_mod[2] == 0) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    cin >> h >> w;
    rep(i, h) rep(j, w) {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    each(m, mp) {
        mp_mod[m.second % 4]++;
    }
    solve();
    return 0;
}
