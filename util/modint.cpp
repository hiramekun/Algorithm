#include <bits/stdc++.h>
// http://noshi91.hatenablog.com/entry/2019/03/31/174006

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
