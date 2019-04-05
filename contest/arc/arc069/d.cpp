#include <cstring>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
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
typedef pair<ll, ll> P;

ump mp;

bool nextT(char now, bool isT, bool prevT) {
    if (now == 'x') {
        if (isT) return !prevT;
        else return prevT;
    } else {
        if (isT) return prevT;
        else return !prevT;
    }
}

bool compare(ll idx, vector<bool> ansT) {
    if (idx == 0) return ansT.back() == ansT[idx + 1];
    else if (idx == ansT.size() - 1) return ansT[idx - 1] == ansT[0];
    else return ansT[idx - 1] == ansT[idx + 1];
}


int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        mp = ump();
#pragma clang diagnostic pop
#endif
        ll n;
        string s;
        cin >> n >> s;

        rep(num, 4) {
            vector<bool> ansT(n);
            rep(i, n) ansT[i] = false;
            ansT[0] = ((num & 1) == 1);
            ansT[1] = ((num >> 1 & 1) == 1);
            for (int i = 1; i < n - 1; ++i) {
                ansT[i + 1] = nextT(s[i], ansT[i], ansT[i - 1]);
            }

            bool b = false;
            // check
            for (int i = 0; i < n; ++i) {
                if (ansT[i]) { // sheep
                    if (s[i] == 'o') {
                        if (compare(i, ansT)) {
                            // yes
                        } else {
                            // no
                            b = true;
                            break;
                        }
                    } else {
                        if (!compare(i, ansT)) {
                            // ok
                        } else {
                            // no
                            b = true;
                            break;
                        }
                    }
                } else {
                    if (s[i] == 'o') {
                        if (!compare(i, ansT)) {
                            // ok
                        } else {
                            // no
                            b = true;
                            break;
                        }
                    } else {
                        if (compare(i, ansT)) {
                            // ok
                        } else {
                            // no
                            b = true;
                            break;
                        }
                    }
                }
            }
            if (b) continue;
            rep(i, n) {
                if (ansT[i]) cout << 'S';
                else cout << 'W';
            }
            return 0;
        }
        cout << -1 << endl;
#ifdef MY_DEBUG
    }
#endif
    return 0;
}