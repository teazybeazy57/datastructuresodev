#include <stdio.h>
void diziYazdir(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5, i, pos, value;
    // Eleman Ekleme (Araya ekleme)
    pos = 2; // 2. indexe ekle
    value = 25;
    for (i = n - 1; i >= pos; i--) arr[i + 1] = arr[i];
    arr[pos] = value;
    n++;
    printf("Ekleme sonrasi: ");
    diziYazdir(arr, n);
    // Eleman Silme
    pos = 3; // 3. indexi sil
    for (i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
    printf("Silme sonrasi: ");
    diziYazdir(arr, n);
    return 0;
}
