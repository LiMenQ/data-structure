#include "List.c"

int main(){

    ListNode* pHead = ListCreate();
    ListPushBack(pHead, 1);
    ListPushBack(pHead, 2);
    ListPushBack(pHead, 3);
    ListPushBack(pHead, 4);
    ListPopBack(pHead);
    ListPopBack(pHead);
    ListPopBack(pHead);
    ListPushFront(pHead, 3);
    ListPushFront(pHead, 5);
    ListPushFront(pHead, 4);
    ListPopFront(pHead);
    ListNode* node = ListFind(pHead, 3);
    ListInsert(node, 4);
    ListInsert(node, 4);
    ListErase(node);
    printf("%d\n", node->val);
    ListPrint(pHead);
    ListDestory(pHead);
    return 0;
}