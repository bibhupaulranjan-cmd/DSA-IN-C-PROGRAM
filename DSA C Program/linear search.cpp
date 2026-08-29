
#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n, key, i;
    int found = 0;
    int positions[MAX], count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            positions[count++] = i + 1; 
            found = 1;
        }
    }

    if (found) {
        printf("Element %d found at position(s): ", key);
        for (i = 0; i < count; i++)
            printf("%d ", positions[i]);
        printf("\n");
        printf("Total occurrences: %d\n", count);
    } else {
        printf("Element %d not found in the list.\n", key);
    }

    return 0;
}
