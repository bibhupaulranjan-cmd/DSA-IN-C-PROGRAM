
#include <stdio.h>

int main() {
    int arr[100], n, i;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ptr = arr;

    printf("\nForward direction:\n");
    for (i = 0; i < n; i++)
        printf("Element = %d\tAddress = %p\n", *(ptr + i), (void *)(ptr + i));

    printf("\nBackward direction:\n");
    for (i = n - 1; i >= 0; i--)
        printf("Element = %d\tAddress = %p\n", *(ptr + i), (void *)(ptr + i));

    return 0;
}
