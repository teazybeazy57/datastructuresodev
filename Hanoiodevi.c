#include <stdio.h>
void hanoi(int n, char kaynak, char ara, char hedef) {
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", kaynak, hedef);
        return;
    }
    hanoi(n - 1, kaynak, hedef, ara);
    printf("Disk %d: %c -> %c\n", n, kaynak, hedef);
    hanoi(n - 1, ara, kaynak, hedef);
}
int main() {
    int n;
    printf("Disk sayisi: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
