#include <stdio.h>
int stack_arr[4];
int top = -1;
void push(int data)
{
    if (top == 4 - 1)
    {
        printf("Stack overflowed!");
    }
    else
    {
        top = top + 1;
        stack_arr[top] = data;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("Element pushed: %d", stack_arr[top]);
    return 0;
}
