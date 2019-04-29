#include <iostream>
using namespace std;

int b[1000];

void merge_sort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    for (int i = low; i <= mid; i++) {
        b[i] = arr[i];
    }
    for (int i = mid + 1, j = high; i <= high; i++, j--) {
        b[i] = arr[j];
    }

    int i = low;
    int j = high;
    for (int k = low; k <= high; k++) {
        if (b[i] <= b[j]) {
            arr[k] = b[i++];
        } else {
            arr[k] = b[j--];
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int a[5] = {9, 2, 20, 3, 8};
    merge_sort(a, 0, 4);
    print_array(a, 5);
    return 0;
}
