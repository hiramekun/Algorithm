/**
 * Created by hiramekun at 22:59 on 2019-08-28.
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = ll(n - 1); i >= 0; i--)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}


template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<vector<T>> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << '\n';
    return out;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
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

modint<mod> dp[e5 + 5][2]; // i桁目まで見た時の条件を満たすような組の個数
void solve() {
    string l;
    cin >> l;

    ll n = l.size();

    dp[0][1] = 1;
    const ll LT = 0, EQ = 1;
    rep(i, n) {
        if (l[i] == '1') {
            // a + b = 0;
            dp[i + 1][LT] += dp[i][LT];
            dp[i + 1][LT] += dp[i][EQ];
            // a + b = 1;
            dp[i + 1][EQ] += dp[i][EQ] * 2;
            dp[i + 1][LT] += dp[i][LT] * 2;
        } else {
            // a + b = 0;
            dp[i + 1][EQ] += dp[i][EQ];
            dp[i + 1][LT] += dp[i][LT];
            // a + b = 1;
            dp[i + 1][LT] += dp[i][LT] * 2;
        }
    }
    cout << (dp[n][1] + dp[n][0]).x << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}


