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
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll half_inf = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);
typedef unordered_map<ll, ll> mpll;
typedef unordered_map<char, ll> mpcl;
typedef unordered_map<string, ll> mpsl;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

ll inl() {
    ll x;
    cin >> x;
    return (x);
}

string ins() {
    string x;
    cin >> x;
    return (x);
}

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll h, w, n, sr, sc;
        string s, t;
        cin >> h >> w >> n >> sr >> sc;
        cin >> s >> t;
        sr--, sc--;
        const int U = 0, D = 1, L = 2, R = 3;
        char vs[] = {'U', 'D', 'L', 'R'};
        ll d1[n + 1][4], d2[n + 1][4];
        ll maxd2[n + 1][4];
        rep(i, 4) {
            d1[0][i] = d2[0][i] = 0;
        }

        rep(i, n) {
            rep(j, 4) {
                if (s[i] == vs[j]) d1[i + 1][j] = d1[i][j] + 1;
                else d1[i + 1][j] = d1[i][j];

                if (t[i] == vs[j]) d2[i + 1][j] = d2[i][j] + 1;
                else d2[i + 1][j] = d2[i][j];
            }
        }
        rep(i, 4) {
            maxd2[0][i] = 0;
            maxd2[1][i] = d2[1][i];
        }

        for (int i = 1; i <= n; ++i) {
            // 移動できる最大回数
            maxd2[i][U] = min({maxd2[i][U], max(0LL, sc - d1[i][U]), d2[i][U]});
            maxd2[i][D] = min({maxd2[i][D], max(0LL, h - 1 - sc - d1[i][D]), d2[i][D]});
            maxd2[i][L] = min({maxd2[i][L], max(0LL, sr - d1[i][L]), d2[i][L]});
            maxd2[i][R] = min({maxd2[i][R], max(0LL, w - 1 - sr - d1[i][R]), d2[i][R]});
            if (i < n) rep(j, 4) maxd2[i + 1][j] = maxd2[i][j];
        }

        for (int i = 0; i < n; i++) {
            if (sc - d1[i + 1][U] + maxd2[i][D] < 0) {
                cout << "NO" << endl;
                return 0;
            }
            if (sc + d1[i + 1][D] - maxd2[i][U] > h - 1) {
                cout << "NO" << endl;
                return 0;
            }
            if (sr - d1[i + 1][L] + maxd2[i][R] < 0) {
                cout << "NO" << endl;
                return 0;
            }
            if (sr + d1[i + 1][R] - maxd2[i][L] > w - 1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;

#ifdef MY_DEBUG
    }

#endif
    return 0;
}