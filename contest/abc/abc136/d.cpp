#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using v = vector<T>;
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        string s;
        cin >> s;

        ll n = s.size();

        v<P> r_to_l(n, P(-1, -1));
        stack<ll> st;
        for (long long i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                st.push(i);
            } else {
                ll d = 1;
                while (!st.empty()) {
                    ll top = st.top();
                    st.pop();
                    r_to_l[top] = P(i, d);
                    d++;
                }
            }
        }
        v<P> l_to_r(n, P(-1, -1));
        stack<ll> stt;
        for (long long i = n - 1; i >= 0; --i) {
            if (s[i] == 'L') {
                stt.push(i);
            } else {
                ll d = 1;
                while (!stt.empty()) {
                    ll top = stt.top();
                    stt.pop();
                    l_to_r[top] = P(i, d);
                    d++;
                }
            }
        }

        vl ans(n, 0);
        for (long long i = 0; i < n; i++) {
            if (s[i] == 'R') {
                ll l_idx = r_to_l[i].F;
                ll d = r_to_l[i].S;

                ans[l_idx - d % 2]++;
            } else {
                ll r_idx = l_to_r[i].F;
                ll d = l_to_r[i].S;

                ans[r_idx + d % 2]++;
            }
        }

        rep(i, n) cout << ans[i] << ' ';


#ifdef MY_DEBUG
    }
#endif
    return 0;
}
