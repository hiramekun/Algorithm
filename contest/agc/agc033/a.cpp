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
        ll h = inl(), w = inl();
        char a[h][w];

        vector<P> black;
        vector<P> black2;
        rep(i, h) {
            rep(j, w) {
                cin >> a[i][j];
                if (a[i][j] == '#') black.eb(P(i, j));
            }
        }

        ll ans = 0;

        while (!black.empty()) {
            bool b = false;
            for (auto t: black) {
                ll i = t.F, j = t.S;
                rep(k, 4) {
                    ll nx = i + dx[k], ny = j + dy[k];

                    if (nx >= 0 && nx <= h - 1 && ny >= 0 && ny <= w - 1 && a[nx][ny] == '.') {
                        a[nx][ny] = '#';
                        black2.eb(P(nx, ny));
                        if (!b) {
                            ans++;
                            b = true;
                        }
                    }
                }
            }
            black = black2;
            black2.clear();
        }
        cout << ans << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}