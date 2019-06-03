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
        ll n = inl(), a = inl(), b = inl(), c = inl(), d = inl();
        a--, b--, c--, d--;
        string s = ins();
        if (c < d) {
            for (int i = a; i < d; i++) {
                if (s[i] == '#' && s[i + 1] == '#') {
                    cout << "No" << endl;
                    return 0;
                }
            }
            cout << "Yes" << endl;
            return 0;
        } else {
            for (int i = a; i < c; i++) {
                if (s[i] == '#' && s[i + 1] == '#') {
                    cout << "No" << endl;
                    return 0;
                }
            }
            if (a + 2 == b && s[a + 1] == '.') a++;

            for (int i = a; i <= d; i++) {
                if ((i == d && s[i + 1] == '#') || (s[i] == '#' && i + 1 == d)) {
                    cout << "No" << endl;
                    return 0;
                }
                if (b - 1 <= i && i + 1 <= d) {
                    if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
            cout << "No" << endl;
            return 0;
        }

#ifdef MY_DEBUG
    }

#endif
    return 0;
}
