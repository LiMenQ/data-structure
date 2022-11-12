#include "Queue.c"

int main(){

    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    QueuePush(&q, 5);
    QueuePop(&q);
    QueuePop(&q);
    printf("%d\n", QueueFront(&q));
    printf("%d\n", QueueBack(&q));
    printf("%d\n", QueueSize(&q));
    printf("%d\n", QueueEmpty(&q));
    QueuePrint(&q);
    QueueDestroy(&q);
    return 0;
}