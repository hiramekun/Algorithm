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

string s, t;

void solve() {
    int same_c = 0;
    int start = -1;
    repr(i, s.length()) {
        int temp = i;
        repr(j, t.length()) {
            if (temp >= 0 && (s[temp] == t[j] || s[temp] == '?')) {
                same_c++;
                temp--;
            } else {
                same_c = 0;
                break;
            }
        }
        if (same_c == t.length()) {
            start = temp + 1;
            break;
        }
    }
    if (start == -1) cout << "UNRESTORABLE" << endl;
    else {
        rep(i, start) {
            if (s[i] == '?') cout << 'a';
            else cout << s[i];
        }
        for (int j = start; j < start + t.length(); ++j) {
            cout << t[j - start];
        }
        for (int i = start + t.length(); i < s.length(); ++i) {
            if (s[i] == '?') cout << 'a';
            else cout << s[i];
        }
    }
}

int main() {
    cin >> s >> t;
    solve();
    return 0;
}
