
#include <stdio.h>

#define MAX 10

int main() {
    int arr[MAX][MAX];
    int rows, cols, i, j;
    int rowMin, rowMax, colMin, colMax;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter %d elements:\n", rows * cols);
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);

    printf("\n--- Row-wise smallest and largest ---\n");
    for (i = 0; i < rows; i++) {
        rowMin = rowMax = arr[i][0];
        for (j = 1; j < cols; j++) {
            if (arr[i][j] < rowMin) rowMin = arr[i][j];
            if (arr[i][j] > rowMax) rowMax = arr[i][j];
        }
        printf("Row %d: Smallest = %d, Largest = %d\n", i + 1, rowMin, rowMax);
    }

    printf("\n--- Column-wise smallest and largest ---\n");
    for (j = 0; j < cols; j++) {
        colMin = colMax = arr[0][j];
        for (i = 1; i < rows; i++) {
            if (arr[i][j] < colMin) colMin = arr[i][j];
            if (arr[i][j] > colMax) colMax = arr[i][j];
        }
        printf("Column %d: Smallest = %d, Largest = %d\n", j + 1, colMin, colMax);
    }

    return 0;
}
