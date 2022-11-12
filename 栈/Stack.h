#include <stdio.h>
#include <stdlib.h>

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// 栈顶
	int capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps); 
// 入栈 
void StackPush(Stack* ps, STDataType data); 
// 出栈 
void StackPop(Stack* ps); 
// 获取栈顶元素 
STDataType StackTop(Stack* ps); 
// 获取栈中有效元素个数 
int StackSize(Stack* ps); 
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps); 
// 销毁栈 
void StackDestroy(Stack* ps); 
// 为了方便调试 打印栈内信息
void StackPrint(Stack* ps);