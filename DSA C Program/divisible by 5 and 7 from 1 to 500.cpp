
#include <stdio.h>

int main() {
    int i;
    printf("Numbers between 1 and 500 divisible by both 5 and 7:\n");
    for (i = 1; i <= 500; i++) {
        if (i % 5 == 0 && i % 7 == 0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
