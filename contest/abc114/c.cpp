#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define i_inf int(1e9)
#define i_half_inf int(1e5)
#define ll_inf ll(1e9)*ll(1e9)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for(ll i = n - 1; i >= 0; i--)
#define repone(i, n) for(ll i = 1; i <= (ll)(n); i++)
#define each(i, mp) for(auto i:mp)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


ll N;

vector<ll> each_digit(ll S) {
    ll n_len = 0, n_dig[9];
    while (S > 0) {
        n_dig[n_len++] = S % 10;
        S /= 10;
    }
    vector<ll> ret(n_dig, n_dig + n_len);
    return ret;
}

void solve() {
    ll rank = each_digit(N).size();
    ll ans = 0;
    int temp[3] = {3, 5, 7};
    unordered_map<ll, ll> mp;

    each(i, temp) {
        each(j, temp) {
            each(k, temp) {
                if (i != 3 && j != 3 && k != 3 ||
                    i != 5 && j != 5 && k != 5 ||
                    i != 7 && j != 7 && k != 7) {
                } else {
                    string a;
                    a += to_string(i);
                    a += to_string(j);
                    a += to_string(k);
                    ll num = stoi(a);
                    if (num <= N && mp[num] == 0) {
                        ans++;
                        mp[num]++;
                    }
                }
                if (rank < 4) {
                    continue;
                }
                each(l, temp) {
                    if (i != 3 && j != 3 && k != 3 && l != 3 ||
                        i != 5 && j != 5 && k != 5 && l != 5 ||
                        i != 7 && j != 7 && k != 7 && l != 7) {
                    } else {
                        string a;
                        a += to_string(i);
                        a += to_string(j);
                        a += to_string(k);
                        a += to_string(l);
                        ll num = stoi(a);
                        if (num <= N && mp[num] == 0) {
                            ans++;
                            mp[num]++;
                        }
                    }
                    if (rank < 5) {
                        continue;
                    }
                    each(m, temp) {
                        if (i != 3 && j != 3 && k != 3 && l != 3 && m != 3 ||
                            i != 5 && j != 5 && k != 5 && l != 5 && m != 5 ||
                            i != 7 && j != 7 && k != 7 && l != 7 && m != 7) {
                        } else {
                            string a;
                            a += to_string(i);
                            a += to_string(j);
                            a += to_string(k);
                            a += to_string(l);
                            a += to_string(m);
                            ll num = stoi(a);
                            if (num <= N && mp[num] == 0) {
                                ans++;
                                mp[num]++;
                            }
                        }
                        if (rank < 6) {
                            continue;
                        }
                        each(n, temp) {
                            if (i != 3 && j != 3 && k != 3 && l != 3 && m != 3 && n != 3 ||
                                i != 5 && j != 5 && k != 5 && l != 5 && m != 5 && n != 5 ||
                                i != 7 && j != 7 && k != 7 && l != 7 && m != 7 && n != 7) {
                            } else {
                                string a;
                                a += to_string(i);
                                a += to_string(j);
                                a += to_string(k);
                                a += to_string(l);
                                a += to_string(m);
                                a += to_string(n);
                                ll num = stoi(a);
                                if (num <= N && mp[num] == 0) {
                                    ans++;
                                    mp[num]++;
                                }
                            }
                            if (rank < 7) {
                                continue;
                            }
                            each(o, temp) {
                                if (i != 3 && j != 3 && k != 3 && l != 3 && m != 3 && n != 3 && o != 3 ||
                                    i != 5 && j != 5 && k != 5 && l != 5 && m != 5 && n != 5 && o != 5 ||
                                    i != 7 && j != 7 && k != 7 && l != 7 && m != 7 && n != 7 && o != 7) {
                                } else {
                                    string a;
                                    a += to_string(i);
                                    a += to_string(j);
                                    a += to_string(k);
                                    a += to_string(l);
                                    a += to_string(m);
                                    a += to_string(n);
                                    a += to_string(o);
                                    ll num = stoi(a);
                                    if (num <= N && mp[num] == 0) {
                                        ans++;
                                        mp[num]++;
                                    }
                                }
                                if (rank < 8) {
                                    continue;
                                }
                                each(p, temp) {
                                    if (i != 3 && j != 3 && k != 3 && l != 3 && m != 3 && n != 3 && o != 3 &&
                                        p != 3 ||
                                        i != 5 && j != 5 && k != 5 && l != 5 && m != 5 && n != 5 && o != 5 &&
                                        p != 5 ||
                                        i != 7 && j != 7 && k != 7 && l != 7 && m != 7 && n != 7 && o != 7 &&
                                        p != 7) {
                                    } else {
                                        string a;
                                        a += to_string(i);
                                        a += to_string(j);
                                        a += to_string(k);
                                        a += to_string(l);
                                        a += to_string(m);
                                        a += to_string(n);
                                        a += to_string(o);
                                        a += to_string(p);
                                        ll num = stoi(a);
                                        if (num <= N && mp[num] == 0) {
                                            ans++;
                                            mp[num]++;
                                        }
                                    }
                                    if (rank < 9) {
                                        continue;
                                    }
                                    each(q, temp) {
                                        if (i != 3 && j != 3 && k != 3 && l != 3 && m != 3 && n != 3 && o != 3 &&
                                            p != 3 && q != 3 ||
                                            i != 5 && j != 5 && k != 5 && l != 5 && m != 5 && n != 5 && o != 5 &&
                                            p != 5 && q != 5 ||
                                            i != 7 && j != 7 && k != 7 && l != 7 && m != 7 && n != 7 && o != 7 &&
                                            p != 7 && q != 7) {
                                        } else {
                                            string a;
                                            a += to_string(i);
                                            a += to_string(j);
                                            a += to_string(k);
                                            a += to_string(l);
                                            a += to_string(m);
                                            a += to_string(n);
                                            a += to_string(o);
                                            a += to_string(p);
                                            a += to_string(q);
                                            ll num = stoi(a);
                                            if (num <= N && mp[num] == 0) {
                                                ans++;
                                                mp[num]++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> N;
    solve();
    return 0;
}
