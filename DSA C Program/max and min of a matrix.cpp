#include <stdio.h>

void findMaxMin(int *arr, int rows, int cols, int *max, int *min) {
    int *ptr = arr;
    *max = *min = *ptr;

    for (int i = 0; i < rows * cols; i++) {
        if (*(ptr + i) > *max)
            *max = *(ptr + i);
        if (*(ptr + i) < *min)
            *min = *(ptr + i);
    }
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

    int max, min;
    findMaxMin((int *)matrix, rows, cols, &max, &min);

    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    return 0;
}
