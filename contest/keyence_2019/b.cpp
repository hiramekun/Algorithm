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
#define FOR(i, m, n) for(ll i = m;i < n;i++)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

int main() {
    string s;
    cin >> s;
    string k = "keyence";
    if (s.length() < k.length()) {
        cout << "NO" << endl;
        return 0;
    }
    if (s.substr(0, k.length()) == k) {
        cout << "YES" << endl;
        return 0;
    }
    if (s.substr(s.length() - k.length(), k.length()) == k) {
        cout << "YES" << endl;
        return 0;
    }
    int is = 0, ik = 0;
    string ans;
    while (s[is] == k[ik]) {
        ans += s[is];
        is++;
        ik++;
    }
    is = s.length() - 1, ik = k.length() - 1;
    string a2;
    while (s[is] == k[ik]) {
        a2 = s[is] + a2;
        if (ans + a2 == k) {
            cout << "YES" << endl;
            return 0;
        }
        is--;
        ik--;
    }
    cout << "NO" << endl;
    return 0;
}
