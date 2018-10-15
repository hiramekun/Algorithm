#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <set>

using namespace std;


void print(const vector<int> &v) {
    for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}

void print(const int v[], int n) {
    std::for_each(v, v + n, [](int x) {
        std::cout << x << " ";
    });
    std::cout << std::endl;
}
