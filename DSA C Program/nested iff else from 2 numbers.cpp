
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b) {
        if (a == b)
            printf("Both numbers are equal.\n");
        else
            printf("Maximum = %d, Minimum = %d\n", a, b);
    } else {
        if (a == b)
            printf("Both numbers are equal.\n");
        else
            printf("Maximum = %d, Minimum = %d\n", b, a);
    }

    return 0;
}
