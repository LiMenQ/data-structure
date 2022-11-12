#include "Stack.c"

int main(){

    Stack stack;
    Stack* ps = &stack;
    StackInit(ps);
    StackPush(ps, 1);
    StackPush(ps, 2);
    StackPush(ps, 3);
    StackPush(ps, 4);
    StackPush(ps, 5);
    StackPop(ps);
    StackPop(ps);
    printf("%d\n", StackSize(ps));
    printf("%d\n", StackEmpty(ps));
    StackPrint(ps);

    return 0;
}