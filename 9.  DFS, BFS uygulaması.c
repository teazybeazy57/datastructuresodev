#include <stdio.h>
int q[20], front = -1, rear = -1, vis[20];
int a[20][20], n;
void add(int item) {
    if (rear == 19) return;
    if (front == -1) front = 0;
    q[++rear] = item;
}
int delete() {
    int item;
    if (front == -1 || front > rear) return -1;
    item = q[front++];
    return item;
}
void bfs(int s) {
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete();
    if (p != -1) printf("%d ", p);
    while (p != -1) {
        for (i = 1; i <= n; i++)
            if (a[p][i] == 1 && vis[i] == 0) {
                add(i);
                vis[i] = 1;
            }
        p = delete();
        if (p != -1) printf("%d ", p);
    }
}
void dfs(int s) {
    int i;
    vis[s] = 1;
    printf("%d ", s);
    for (i = 1; i <= n; i++)
        if (a[s][i] == 1 && vis[i] == 0) dfs(i);
}
int main() {
    int i, j, s;
    printf("Dugum sayisi: ");
    scanf("%d", &n);
    printf("Matrisi girin:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    printf("Baslangic dugumu: ");
    scanf("%d", &s);
    for (i = 1; i <= n; i++) vis[i] = 0;
    printf("BFS: ");
    bfs(s);
    for (i = 1; i <= n; i++) vis[i] = 0;
    printf("\nDFS: ");
    dfs(s);
    return 0;
}
