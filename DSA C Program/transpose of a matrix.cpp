
#include <stdio.h>

#define MAX 10

int main() {
    int arr[MAX][MAX], transpose[MAX][MAX];
    int rows, cols, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter %d elements:\n", rows * cols);
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            transpose[j][i] = arr[i][j];

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }

    printf("\nTranspose Matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++)
            printf("%d\t", transpose[i][j]);
        printf("\n");
    }

    return 0;
}
