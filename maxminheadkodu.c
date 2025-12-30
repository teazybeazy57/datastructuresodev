#include <stdio.h>
int size = 0;
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int arr[], int size, int i) {
    if (size == 1) return;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[largest]) largest = l;
    if (r < size && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}
void insert(int arr[], int newNum) {
    if (size == 0) {
        arr[0] = newNum;
        size += 1;
    } else {
        arr[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);
    }
}
int main() {
    int arr[10];
    insert(arr, 3);
    insert(arr, 4);
    insert(arr, 9);
    insert(arr, 5);
    insert(arr, 2);
    printf("Max-Heap dizisi: ");
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
