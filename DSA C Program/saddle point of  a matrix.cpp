#include <stdio.h>

void findSaddlePoint(int *arr, int rows, int cols) {
    int found = 0;

    for (int i = 0; i < rows; i++) {
        int *rowPtr = arr + i * cols;
        int minVal = *rowPtr;
        int minCol = 0;

        for (int j = 1; j < cols; j++) {
            if (*(rowPtr + j) < minVal) {
                minVal = *(rowPtr + j);
                minCol = j;
            }
        }
        int isMaxInCol = 1;
        for (int k = 0; k < rows; k++) {
            int *colElemPtr = arr + k * cols + minCol;
            if (*colElemPtr > minVal) {
                isMaxInCol = 0;
                break;
            }
        }

        if (isMaxInCol) {
            printf("Saddle point found: %d at position (row %d, col %d)\n",
                   minVal, i, minCol);
            found = 1;
        }
    }

    if (!found)
        printf("No saddle point exists in the matrix.\n");
}

int main() {
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", (*(matrix + i) + j));

    findSaddlePoint((int *)matrix, rows, cols);

    return 0;
}
