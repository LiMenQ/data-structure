#include "SList.c"

int main(){
    SListNode* list = BuySListNode(0);
    SListPushBack(list, 1);
    SListPushBack(list, 2);
    SListPushBack(list, 3);
    SListPushBack(list, 4);
    SListPushFront(list, 0);
    SListPopBack(list);
    SListPopFront(list);
    SListNode* node = SListFind(list, 2);
    SListInsertAfter(node, 4);
    SListEraseAfter(node);
    SListPrint(list);
    SListDestroy(list);
    free(list);
    list = NULL;
    return 0;
}