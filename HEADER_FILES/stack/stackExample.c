#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main()
{
    int no, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Check if stack is empty");
    printf("\n 4 - Stack Length");
    printf("\n 5 - Exit");
 
    Stack *stack = createStack ();
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(stack, no);
            break;

        case 2:
            printf("TOP : %d ", pop(stack));
            break;

        case 3:
            isStackEmpty (stack);
            break;

        case 4:
            printf("Length of Stack = %d\n", stack->length);
            break;

        case 5:
            exit(0);
            break;

        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
    return 0;
}