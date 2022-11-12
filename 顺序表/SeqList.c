#include "SeqList.h"

void SeqListInit(SeqList* ps){
    //默认开4个
    ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
    ps->size = 0;
    ps->capacity = 4;
}

void SeqListDestroy(SeqList* ps){
    free(ps->a);
    ps->size = 0;
    ps->capacity = 0;
}

//扩容
void ListExpansion(SeqList* ps){
    ps->capacity = 2 * ps->capacity;
    ps->a = (SLDateType*)realloc(ps->a, ps->capacity * sizeof(SLDateType));
}

 
void SeqListPrint(SeqList* ps){
    for(int i = 0; i < ps->size; i++){
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x){
    if(ps->size == ps->capacity){
        ListExpansion(ps);
    }
    ps->a[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, SLDateType x){
    if(ps->size == ps->capacity){
        ListExpansion(ps);
    }
    for(int i = ps->size - 1; i >= 0; i--){
        ps->a[i + 1] = ps->a[i];
    }
    ps->a[0] = x;
    ps->size++;
}

void SeqListPopFront(SeqList* ps){
    for(int i = 1; i < ps->size; i++){
        ps->a[i-1] = ps->a[i];
    }
    ps->size--;
}
void SeqListPopBack(SeqList* ps){
    ps->size--;
}
 
// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x){
    for(int i = 0; i < ps->size; i++){
        if(ps->a[i] == x)
            return i;
    }
    return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x){
    if(ps->size == ps->capacity){
        ListExpansion(ps);
    }
    for(int i = ps->size - 1; i >= pos; i--){
        ps->a[i+1] = ps->a[i];
    }
    ps->a[pos] = x;
    ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos){
    for(int i = pos; i < ps->size; i++){
        ps->a[i] = ps->a[i+1];
    }
    ps->size--;
}