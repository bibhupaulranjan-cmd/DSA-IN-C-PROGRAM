#include <stdio.h>
#include <limits.h>

void findSecondMaxMin(int *arr, int n, int *secMax, int *secMin) {
    int max = INT_MIN, min = INT_MAX;
    *secMax = INT_MIN;
    *secMin = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > max)
            max = *(arr + i);
        if (*(arr + i) < min)
            min = *(arr + i);
    }
    for (int i = 0; i < n; i++) {
        int val = *(arr + i);

        if (val != max && val > *secMax)
            *secMax = val;

        if (val != min && val < *secMin)
            *secMin = val;
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

    int n = rows * cols;
    int secMax, secMin;
    findSecondMaxMin((int *)matrix, n, &secMax, &secMin);

    if (secMax == INT_MIN || secMin == INT_MAX)
        printf("All elements are equal — no distinct second max/min exists.\n");
    else {
        printf("Second Maximum element = %d\n", secMax);
        printf("Second Minimum element = %d\n", secMin);
    }

    return 0;
}
