#include <stdio.h>

#define MAX_ROW 4
#define MAX_COL 5

int main() {
    int matrix[MAX_ROW][MAX_COL] = {
        {0, 0, 3, 0, 0},
        {0, 0, 0, 0, 2},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 6, 0}
    };

    int nonZeroCount = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    int sparseMatrix[nonZeroCount + 1][3];

    sparseMatrix[0][0] = MAX_ROW;
    sparseMatrix[0][1] = MAX_COL;
    sparseMatrix[0][2] = nonZeroCount;

    int k = 1; 
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;           
                sparseMatrix[k][1] = j;           
                sparseMatrix[k][2] = matrix[i][j]; 
                k++;
            }
        }
    }

    printf("Satir\tSutun\tDeger\n");
    printf("--------------------------\n");
    for (int i = 0; i <= nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}
