#include <stdio.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;
 
// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);
 
void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);