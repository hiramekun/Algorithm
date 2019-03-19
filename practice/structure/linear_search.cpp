#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class LinearSearch {
    private:
        vector<int> data;
    public:
        void add(int a) {
            data.emplace_back(a);
        }

        int find(int a) {
            for (int i = 0; i < data.size(); i++) {
                if (data[i] == a) {
                    return i;
                }
            }
            return -1;
        }
};

int main(int argc, char* argv[]) {
     LinearSearch linearSearch = new LinearSearch();
     int n, k;
     cin >> n >> k;
     for (int i = 0; i < n; i++) {
         int a;
         cin >> a;
         linearSearch.add(a);
     }
     cout << linearSearch.search(k) << endl;
}

