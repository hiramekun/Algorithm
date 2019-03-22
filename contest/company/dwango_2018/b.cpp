#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <numeric>
#include <stack>

using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> ump;
typedef pair<ll, ll> p;

ump mp;

int main() {
#ifdef my_debug
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        string s;
        cin >> s;
        string temp = s;
        int ans = 0;
        while (!temp.empty()) {
            int bef = 5;
            string tp;
            rep(i, temp.size()) {
                if (bef == 5 && temp[i] == '2') {
                    bef = 2;
                } else if (bef == 2 && temp[i] == '5') {
                    bef = 5;
                } else {
                    tp += temp[i];
                };
            }
            if (bef == 2) tp += '2';
            if (temp == tp) {
                cout << -1 << endl;
                return 0;
            }
            temp = tp;
            ans++;
        }
        cout << ans << endl;


#ifdef my_debug
    }
#endif
    return 0;
}