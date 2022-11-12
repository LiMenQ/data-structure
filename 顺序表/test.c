#include "SeqList.c"

int main(){
    SeqList list;
    SeqListInit(&list);

    SeqListPushBack(&list, 1);
    SeqListPushBack(&list, 2);
    SeqListPushBack(&list, 3);
    SeqListPushBack(&list, 4);
    SeqListPushBack(&list, 5);
    SeqListPushFront(&list, 0);
    SeqListPopBack(&list);
    SeqListPopFront(&list);
    SeqListInsert(&list, 1, 10);
    SeqListErase(&list, 1);
    SeqListPrint(&list);
    printf("%d\n", SeqListFind(&list, 10));
    printf("%d\n", SeqListFind(&list, 4));

    SeqListDestroy(&list);
    return 0;
}