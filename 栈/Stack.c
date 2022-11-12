#include "Stack.h"

void StackInit(Stack* ps){
    // 默认初始化4个
    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
    ps->capacity = 4;
    ps->top = 0;
}

void StackPush(Stack* ps, STDataType data){
    if(ps->top == ps->capacity){
        ps->a = (STDataType*)realloc(ps->a, 2 * ps->capacity);
    }
    ps->a[ps->top] = data;
    ps->top++;
}

void StackPop(Stack* ps){
    if(ps->top == 0) return;
    ps->top--;
}

STDataType StackTop(Stack* ps){
    if(ps->top == 0) return INT_MIN;
    return ps->a[ps->top - 1];
}

int StackSize(Stack* ps){
    return ps->top;
}

int StackEmpty(Stack* ps){
    return ps->top == 0;
}

void StackDestroy(Stack* ps){
    free(ps->a);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = 0;    
}

void StackPrint(Stack* ps){
    for(int i = 0; i < ps->top; i++){
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}
