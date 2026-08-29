
#include <stdio.h>

#define N 4

int main() {
    int arr[N][N];
    int i, j;
    int *ptr = &arr[0][0];

    printf("Enter %d elements for a %dx%d matrix:\n", N * N, N, N);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", (ptr + i * N + j));

    printf("\nMain diagonal elements:\n");
    for (i = 0; i < N; i++)
        printf("%d ", *(ptr + i * N + i));
    printf("\n");

    printf("\nSecondary (anti) diagonal elements:\n");
    for (i = 0; i < N; i++)
        printf("%d ", *(ptr + i * N + (N - 1 - i)));
    printf("\n");

    return 0;
}
