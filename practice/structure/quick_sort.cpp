#include <cstdio>
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++){
        printf("%d ", arr[i]);
    } 
}


int main() {
    int arr[] = {1, 30, 3, 4, 8, 2};
    quick_sort(arr, 0, 5);
    printArray(arr, 6);
    return 0;
}
