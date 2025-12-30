#include <stdio.h>
#define MAX 15
char tree[MAX];
void root(char key) {
    if (tree[0] != '\0') printf("Root zaten var");
    else tree[0] = key;
}
void set_left(char key, int parent) {
    if (tree[parent] == '\0') printf("Ebeveyn bulunamadi");
    else tree[(parent * 2) + 1] = key;
}
void set_right(char key, int parent) {
    if (tree[parent] == '\0') printf("Ebeveyn bulunamadi");
    else tree[(parent * 2) + 2] = key;
}
void yazdir() {
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != '\0') printf("%c ", tree[i]);
        else printf("- ");
    }
}
int main() {
    for (int i = 0; i < MAX; i++) tree[i] = '\0';
    root('A');
    set_left('B', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    printf("Agac yapisi (Dizi hali): ");
    yazdir();
    return 0;
}
