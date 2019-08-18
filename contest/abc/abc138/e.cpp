#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
void dump_debug(T list) {
#ifdef MY_DEBUG
    each(e, list) cout << e << " ";
    printf("\n");
#endif
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        string s;
        string t;
        cin >> s >> t;

        ll ns = s.size(), nt = t.size();

        unordered_map<char, vector<ll>> mp;
        rep(i, ns) {
            mp[s[i]].eb(i);
        }
        ll rev = 0;
        ll c = 0;
        ll now = -1;
        rep(i, nt) {
            if (mp[t[i]].empty()) {
                cout << -1 << endl;
                return 0;
            }

            auto itr = upper_bound(all(mp[t[i]]), now);
            if (itr == mp[t[i]].end()) {
                rev++;
                now = mp[t[i]][0];
                c = now + 1;
            } else {
                now = *itr;
                c = now + 1;
            }
        }
        cout << rev * ns + c << endl;
#ifdef MY_DEBUG
    }
#endif
    return 0;
}