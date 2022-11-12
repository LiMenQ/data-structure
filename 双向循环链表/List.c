#include "List.h"

ListNode* buyNode(int val){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

ListNode* ListCreate(){
    ListNode* head = buyNode(-1);
    head->next = head;
    head->prev = head;
    return head;
}

void ListDestory(ListNode* pHead){
    ListNode* cur = pHead->next;
    while(cur != pHead){
        ListNode* pnode = cur;
        cur = cur->next;
        free(pnode);
    }
    free(pHead);
}

void ListPrint(ListNode* pHead){
    ListNode* cur = pHead->next;
    while(cur != pHead){
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

void ListPushBack(ListNode* pHead, LTDataType x){
    ListNode* newNode = buyNode(x);
    newNode->next = pHead;
    newNode->prev = pHead->prev;
    pHead->prev->next = newNode;
    pHead->prev = newNode;
}

void ListPopBack(ListNode* pHead){
    if(pHead->next == pHead) return;
    ListNode* node = pHead->prev;
    node->prev->next = pHead;
    pHead->prev = node->prev;
    free(node);
}

void ListPushFront(ListNode* pHead, LTDataType x){
    ListNode* newNode = buyNode(x);
    newNode->next = pHead->next;
    newNode->prev = pHead;
    pHead->next->prev = newNode;
    pHead->next = newNode;
}

void ListPopFront(ListNode* pHead){
    if(pHead->next == pHead) return;
    ListNode* node = pHead->next;
    pHead->next = node->next;
    node->next->prev = pHead;
}

ListNode* ListFind(ListNode* pHead, LTDataType x){
    ListNode* cur = pHead->next;
    while(cur){
        if(cur->val == x){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void ListInsert(ListNode* pos, LTDataType x){
    if(pos == NULL) return;
    ListNode* newNode = buyNode(x);
    ListNode* prevNode = pos->prev;
    newNode->next = pos;
    newNode->prev = prevNode;
    pos->prev = newNode;
    prevNode->next = newNode;
}

void ListErase(ListNode* pos){
    if(pos == NULL) return;
    ListNode* prevNode = pos->prev;
    prevNode->next = pos->next;
    pos->next->prev = pos->prev;
}
