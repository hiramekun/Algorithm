//
// Created by Takaaki Hirano on 2018/09/01.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(int i = m;i < n;i++)


int N, K;

void solve() {
    unordered_map<ll, ll> mp;
    rep(i, N) mp[(i + 1) % K]++;
    ll ans = 0;
    each(a, mp) {
        ll b = (K - a.first) % K;
        ll c = (K - a.first) % K;
        if ((b + c) % K == 0) ans += a.second * mp[b] * mp[c];
    }

    cout << ans << endl;
}

int main() {
    cin >> N >> K;
    solve();
    return 0;
}
