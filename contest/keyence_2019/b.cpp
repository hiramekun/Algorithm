#include <cstring>
#include <regex>
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
    regex re1(".*keyence");
    regex re2("k.*eyence");
    regex re3("ke.*yence");
    regex re4("key.*ence");
    regex re5("keye.*nce");
    regex re6("keyen.*ce");
    regex re7("keyenc.*e");
    regex re8("keyence.*");

    regex re[8] = {re1, re2, re3, re4, re5, re6, re7, re8};
    rep(i, 8) if (regex_match(s, re[i])) {
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}
