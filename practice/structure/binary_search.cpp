#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
    private:
        vector<int> data;
    public:
        void add(int a) {
            data.emplace_back(a);
        }

        int find(int a) {
            int s = 0;
            int e = data.size() - 1;
            while(e - s > 1) {
                int m = (s + e) / 2;
                if (data[m] == a) {
                    return m;
                } else {
                    if (data[m] > a) {
                        s = m;
                    } else {
                        e = m;
                    }
                }
            }
            return -1;
        }
};

