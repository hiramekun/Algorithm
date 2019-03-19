#include <cstdio>
#include <iostream>

class Heap {
private:
    const int MAX_N = 100;
    int heap[MAX_N];
    int size = 0;
public:
    void push(int x) {
        int i = size++;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] <= x) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    int pop() {
        int ret = heap[0];
        int x = heap[--size];

        int i = 0;
        while (i * 2 + 1 < size) {
            int a = i * 2 + 1, b = i * 2 + 2;
            if (b < size && heap[b] < heap[a]) a = b;

            if (heap[a] >= x) break;

            heap[i] = heap[a];
            i = a;
        }
        heap[i] = x;
        return ret;
    }
};
