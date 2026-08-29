
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int arr[ROWS][COLS];
    int i, j;

    printf("Enter %d elements for a %dx%d matrix:\n", ROWS * COLS, ROWS, COLS);
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            scanf("%d", &arr[i][j]);

    printf("\nForward direction:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Element = %d\tAddress = %p\n",
                   *(*(arr + i) + j), (void *)(*(arr + i) + j));
        }
    }

    printf("\nBackward direction:\n");
    for (i = ROWS - 1; i >= 0; i--) {
        for (j = COLS - 1; j >= 0; j--) {
            printf("Element = %d\tAddress = %p\n",
                   *(*(arr + i) + j), (void *)(*(arr + i) + j));
        }
    }

    return 0;
}
