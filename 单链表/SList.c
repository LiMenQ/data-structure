#include "SList.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x){
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

// 单链表打印
void SListPrint(SListNode* plist){
    SListNode* node = plist->next;
    while(node){
        if(node->next)
            printf("%d->", node->data);
        else
            printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

// 单链表尾插
void SListPushBack(SListNode* plist, SLTDateType x){
    SListNode* newNode = BuySListNode(x);
    SListNode* node = plist;
    while(node->next) node = node->next;
    node->next = newNode;
}

// 单链表的头插
void SListPushFront(SListNode* plist, SLTDateType x){
    SListNode* newNode = BuySListNode(x);
    newNode->next = plist->next;
    plist->next = newNode;
}

// 单链表的尾删
void SListPopBack(SListNode* plist){
    SListNode* node = plist;
    while(node->next && node->next->next) node = node->next;
    free(node->next);
    node->next = NULL;
}

// 单链表头删
void SListPopFront(SListNode* plist){
    SListNode* node = plist;
    if(node->next == NULL) return;
    SListNode* tmp = node->next;
    node->next = node->next->next;
    free(tmp);
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x){
    SListNode* node = plist->next;
    while(node && node->data != x) node = node->next;
    return node;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x){
    SListNode* newNode = BuySListNode(x);
    if(pos->next == NULL) pos->next = newNode;
    else newNode->next = pos->next, pos->next = newNode;
}

// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos){
    if(pos->next == NULL) return;
    SListNode* tmp = pos->next;
    pos->next = pos->next->next;    
    free(tmp);
}

// 单链表的销毁
void SListDestroy(SListNode* plist){
    SListNode* node = plist->next;
    plist->next = NULL;
    while(node){
        SListNode* tmp = node;
        node = node->next;
        free(tmp);
    }
}