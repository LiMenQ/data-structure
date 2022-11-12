#include "Queue.h"

QNode* BuyNode(QDataType data){
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void QueueInit(Queue* q){
    q->front = BuyNode(-1);
    q->rear = q->front;
}

void QueuePush(Queue* q, QDataType data){
    QNode* newNode = BuyNode(data);
    q->rear->next = newNode;
    q->rear = q->rear->next;
} 

void QueuePop(Queue* q){
    if(q->front->next == NULL)
        return;
    QNode* node = q->front->next;
    q->front->next = q->front->next->next;
    free(node);
}

QDataType QueueFront(Queue* q){
    if(q->front->next == NULL) return INT_MIN;
    return q->front->next->data;
}

QDataType QueueBack(Queue* q){
    if(q->front->next == NULL) return INT_MIN;
    return q->rear->data;
} 

int QueueSize(Queue* q){
    int size = 0;
    QNode* cur = q->front->next;
    while(cur){
        size++;
        cur = cur->next;
    }
    return size;
} 

int QueueEmpty(Queue* q){
    return q->front->next == NULL;
} 

void QueueDestroy(Queue* q){
    QNode* cur = q->front->next;
    while(cur){
        QNode* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(q->front);
    q->front = NULL;
    q->rear = NULL;
}


void QueuePrint(Queue* q){
    QNode* cur = q->front->next;
    while(cur){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
