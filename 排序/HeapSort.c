#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void AdjutsDown(int* arr, int size, int k){
    int child = k * 2 + 1;
    while(child < size){
        if(child + 1 < size && arr[child + 1] > arr[child]){
            child = child + 1;
        }
        if(arr[child] > arr[k]){
            swap(&arr[child], &arr[k]);
            k = child;
            child = child * 2 + 1;
        }else{
            break;
        }
    }
}

void HeapSort(int* arr, int size){
    for(int i = (size - 2) / 2; i >= 0; i--){
        AdjutsDown(arr, size, i);
    }

    for(int i = 0; i < size; i++){
        swap(&arr[0], &arr[size - i - 1]);
        AdjutsDown(arr, size - i - 1, 0);
    }
}

int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }
    
    HeapSort(arr, 100);

    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}