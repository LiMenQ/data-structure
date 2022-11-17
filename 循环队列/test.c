#include"CircularQueue.c"

int main(){

    MyCircularQueue* q = CircularQueueCreate(5);
    printf("%d\n", CircularQueueIsEmpty(q)); 
    printf("%d\n", CircularQueueIsFull(q)); 
    CircularQueueEnQueue(q, 1);
    CircularQueueEnQueue(q, 2);
    CircularQueueEnQueue(q, 3);
    CircularQueueEnQueue(q, 4);
    CircularQueueEnQueue(q, 5);
    CircularQueueDeQueue(q);
    CircularQueueDeQueue(q);
    CircularQueueDeQueue(q);
    CircularQueueEnQueue(q, 6);
    CircularQueuePrint(q);
    printf("%d\n", CircularQueueFront(q));
    printf("%d\n", CircularQueueRear(q));
    printf("%d\n", CircularQueueSize(q));
    CircularQueueFree(q);

    return 0;
}