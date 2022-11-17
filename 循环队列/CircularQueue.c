#include "CircularQueue.h"

MyCircularQueue* CircularQueueCreate(int k){
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->front = 0, obj->rear = 0;
    obj->nums = (int*)malloc(sizeof(int) * (k + 1));
    obj->k = k;
    return obj;
}

int CircularQueueIsEmpty(MyCircularQueue* obj){
    return obj->front == obj->rear;
}

int CircularQueueIsFull(MyCircularQueue* obj){
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

void CircularQueueEnQueue(MyCircularQueue* obj, int value){
    if(CircularQueueIsFull(obj)) return;
    obj->nums[obj->rear] = value;
    obj->rear = (obj->rear + 1) % (obj->k + 1);
}

void CircularQueueDeQueue(MyCircularQueue* obj){
    if(CircularQueueIsEmpty(obj)) return;
    obj->front = (obj->front + 1) % (obj->k + 1);
}

int CircularQueueFront(MyCircularQueue* obj){
    if(CircularQueueIsEmpty(obj)) return INT_MIN;
    return obj->nums[obj->front];
}
int CircularQueueRear(MyCircularQueue* obj){
    if(CircularQueueIsFull(obj)) return INT_MIN;
    if(obj->rear == 0) return obj->nums[obj->k];
    return obj->nums[obj->rear - 1];
}

int CircularQueueSize(MyCircularQueue* obj){
    return (obj->rear - obj->front + obj->k + 1) % (obj->k + 1);
}

void CircularQueueFree(MyCircularQueue* obj){
    free(obj->nums);
    obj->nums = NULL;
    obj->k = 0;
    obj->front = 0;
    obj->rear = 0;
    free(obj);
}

void CircularQueuePrint(MyCircularQueue* obj){
    int tmp = obj->front;
    while(tmp != obj->rear){
        printf("%d ", obj->nums[tmp]);
        tmp = (tmp + 1) % (obj->k + 1);
    }
    printf("\n");
}
