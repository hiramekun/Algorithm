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

struct info {
    bool used;
    int col;
};

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n, q;
        cin >> n >> q;
        string s = ins();

        char p[3][2500];
        bool isok[3];
        int idxs[3];
        rep(i, 3) {
            isok[i] = true;
            idxs[i] = 0;
        }

        info used[n];
        rep(j, n)used[n] = {false, -1};
        rep(i, q) {
            char sig;
            int col;
            cin >> sig >> col;
            col--;

            if (sig == '+') {
                char abc;
                scanf("%c", &abc);
                cin >> abc;
                p[col][idxs[col]++] = abc;

                int idx = 0;
                rep(j, n) {
                    if (!used[idx].used && p[col][idx] == s[j]) {
                        used[idx].used = true;
                        used[idx].col = col;
                        idx++;
                    }
                    if (idx == idxs[col]) {
                        isok[col] = true;
                        break;
                    }
                    if (j == n - 1) {
                        isok[col] = false;
                        break;
                    }
                }
                if (isok[0] && isok[1] && isok[2]) cout << "YES" << endl;
                else cout << "NO" << endl;

            } else {
                idxs[col]--;
                used[idxs[col]].used = false;
                used[idxs[col]].col = -1;
                int idx = 0;
                rep(j, n) {
                    if ((!used[idx].used || used[idx].col == col) && p[col][idx] == s[j]) {
                        used[idx].used = true;
                        used[idx].col = col;
                        idx++;
                    }
                    if (idx == idxs[col]) {
                        isok[col] = true;
                        break;
                    }
                    if (j == n - 1) {
                        isok[col] = false;
                        break;
                    }
                }
                if (isok[0] && isok[1] && isok[2]) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }

#ifdef MY_DEBUG
    }
#endif
    return 0;
}