#include"Heap.c"

// TopK问题：找出N个数里面最大的前K个数字
void PrintTopK(int* a, int n, int k){
    int* heap = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++){
        heap[i] = a[i];
        AdjustUp(heap, i);
    }
    
    for(int i = k; i < n; i++){
        if(a[i] > heap[0]){
            heap[0] = a[i];
            AdjustDown(heap, 0, k);
        }
    }

    for(int i = 0; i < k; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main(){

    // Heap heap;
    // HeapCreate(&heap, (&heap)->a, 4);
    // HeapPush(&heap, 5);
    // HeapPush(&heap, 6);
    // HeapPush(&heap, 7);
    // HeapPush(&heap, 1);
    // HeapPush(&heap, 2);
    // HeapPush(&heap, 3);
    // HeapPush(&heap, 0);
    // print(&heap);
    // HeapPop(&heap);
    // print(&heap);
    // HeapPop(&heap);
    // HeapPop(&heap);
    // printf("%d\n", HeapEmpty(&heap));
    // printf("%d\n", HeapSize(&heap));
    // printf("%d\n", HeapTop(&heap));
    // print(&heap);
    // HeapDestory(&heap);

    int a[1000];
    int k = 20; // 取前20最大的数
    for(int i = 0; i < 1000; i++){
        a[i] = rand() % 1000;
    }
    PrintTopK(a, 1000, k);

    return 0;
}