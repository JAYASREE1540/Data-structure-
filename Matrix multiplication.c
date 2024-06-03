#include <stdio.h>

#define ROW_SIZE 3
#define COL_SIZE 3

int main() {
    int mat1[ROW_SIZE][COL_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[ROW_SIZE][COL_SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[ROW_SIZE][COL_SIZE];

    printf("Matrix 1:\n");
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    printf("\nResult:\n");
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < ROW_SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

