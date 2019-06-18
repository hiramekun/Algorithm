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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
void dumplist_debug(T list) {
#ifdef MY_DEBUG
    each(e, list) cout << e << " ";
    printf("\n");
#endif
}

void print_debug(const char *str) {
#ifdef MY_DEBUG
    printf((const char *) str);
#endif
}

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


template<std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

public:
    u64 x;

    constexpr modint(const u64 x = 0) noexcept : x(x % Modulus) {}

    constexpr u64 &value() noexcept { return x; }

    constexpr const u64 &value() const noexcept { return x; }

    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }

    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }

    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }

    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }

    constexpr modint &operator+=(const modint rhs) noexcept {
        x += rhs.x;
        if (x >= Modulus) {
            x -= Modulus;
        }
        return *this;
    }

    constexpr modint &operator-=(const modint rhs) noexcept {
        if (x < rhs.x) {
            x += Modulus;
        }
        x -= rhs.x;
        return *this;
    }

    constexpr modint &operator*=(const modint rhs) noexcept {
        x = x * rhs.x % Modulus;
        return *this;
    }

    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};

typedef vector<modint<mod>> vmod;
typedef vector<vmod> vvmod;



/* ----------- ANSWER ----------- */
/* ------------------------------ */

int main() {
#ifdef MY_DEBUG
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
#pragma clang diagnostic pop
#endif
        ll n, m;
        cin >> n >> m;
        vl s(n), t(m);
        rep(i, n) cin >> s[i];
        rep(i, m) cin >> t[i];

        vvmod dp(n + 1, vmod(m + 1, 0));
        vvmod sum(n + 1, vmod(m + 1, 0));
        // dp[i+1][j+1]: s[i]までと、ちょうどt[j]までで終わるもの

        rep(i, n + 1) {
            dp[i][0] = 1;
            sum[i][0] = 1;
        }
        rep(i, m + 1) sum[0][i] = 1;

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) {
                dp[i + 1][j + 1] = dp[i][j + 1];
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] += sum[i][j];
                }
                sum[i + 1][j + 1] = sum[i + 1][j] + dp[i + 1][j + 1];
            }
        }
        modint<mod> ans = 0;
        rep(i, m + 1) ans += dp[n][i];
        cout << ans.x << endl;

#ifdef MY_DEBUG
    }
#endif
    return 0;
}
