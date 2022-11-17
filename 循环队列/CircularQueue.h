#include<stdio.h>
#include<stdlib.h>

typedef struct MyCircularQueue{
    int* nums;
    int k;  // 队列总长度
    int front;
    int rear;
} MyCircularQueue;

// 初始化队列
MyCircularQueue* CircularQueueCreate(int k);
// 判断是否为空
int CircularQueueIsEmpty(MyCircularQueue* obj);
// 判断是否为满
int CircularQueueIsFull(MyCircularQueue* obj);
// 添加元素
void CircularQueueEnQueue(MyCircularQueue* obj, int value);
// 删除元素
void CircularQueueDeQueue(MyCircularQueue* obj);
// 获取队头元素
int CircularQueueFront(MyCircularQueue* obj);
// 获取队尾元素
int CircularQueueRear(MyCircularQueue* obj);
// 获取队列有效长度
int CircularQueueSize(MyCircularQueue* obj);
// 销毁队列
void CircularQueueFree(MyCircularQueue* obj);
// 为了方便调试 打印队列
void CircularQueuePrint(MyCircularQueue* obj);