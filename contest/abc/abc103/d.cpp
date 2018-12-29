//
// Created by Takaaki Hirano on 2018/08/02.
//
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;
int N, M;

vector<pair<int, int> > ab_pairs;

void solve() {
    // bの昇順にならべかえる
    sort(ab_pairs.begin(), ab_pairs.end());

    int before_removed = 0;
    int sum = 0;
    int a, b;
    for (int i = 0; i < M; i++) {
        a = ab_pairs[i].second, b = ab_pairs[i].first;
        if (before_removed >= a && before_removed < b) {
            continue;
        }
        before_removed = b - 1;
        sum++;
    }

    printf("%d\n", sum);
}

int main() {
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ab_pairs.emplace_back(make_pair(b, a));
    }
    solve();
}

