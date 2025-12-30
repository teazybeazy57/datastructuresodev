#include <stdio.h>
int visited[10] = {0};
void dfs(int v, int n, int graph[10][10]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, n, graph);
        }
    }
}
int main() {
    int n = 6; // Düğüm sayısı
    int graph[10][10] = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };
    int clusterSayisi = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            clusterSayisi++;
            printf("%d. Cluster: ", clusterSayisi);
            dfs(i, n, graph);
            printf("\n");
        }
    }
    return 0;
}
