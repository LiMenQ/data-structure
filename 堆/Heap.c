#include"Heap.h"

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n){
    hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
    hp->size = 0;
    hp->capacity = n;
}

// 堆的销毁
void HeapDestory(Heap* hp){
    free(hp->a);
    hp->a = NULL;
    hp->size = 0;
    hp->capacity = 0;
    free(hp);
}

// 向上调整
void AdjustUp(int* a, int child){
    int parent = (child - 1) / 2;
    while(child > 0){
        if(a[parent] > a[child]){
            HPDataType tmp = a[child];
            a[child] = a[parent];
            a[parent] = tmp;
            child = parent;
            parent = (child - 1) / 2;
        }else{
            break;
        }
    }
}

// 向下调整
void AdjustDown(int* a, int parent, int size){
    int child = parent * 2 + 1;
    while(child < size){
        if(child + 1 < size && a[child + 1] < a[child])
            child = child + 1;
        if(a[child] < a[parent]){
            HPDataType tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;
            parent = child;
            child = parent * 2 + 1;
        }else{
            break;
        }
    }
}

// 堆的判空
int HeapEmpty(Heap* hp){
    return hp->size == 0;
}

// 堆的数据个数
int HeapSize(Heap* hp){
    return hp->size;
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp){
    if(HeapEmpty(hp)) return INT_MIN;
    return hp->a[0];
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x){
    if(hp->size == hp->capacity){
        // 扩容
        hp->a = (HPDataType*)realloc(hp->a, 2 * hp->capacity);
        hp->capacity = 2 * hp->capacity;
    }
    hp->a[hp->size++] = x;
    AdjustUp(hp->a, hp->size - 1);
}

// 堆的删除 即删除堆顶元素
void HeapPop(Heap* hp){
    if(HeapEmpty(hp)) return;
    hp->a[0] = hp->a[hp->size - 1];
    hp->size--;
    AdjustDown(hp->a, 0, hp->size);
}

void print(Heap* hp){
    for(int i = 0; i < hp->size; i++){
        printf("%d ", hp->a[i]);
    }
    printf("\n");
}
