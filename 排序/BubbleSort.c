#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j + 1] < arr[j])
                swap(&arr[j + 1], &arr[j]);
        }
    }
}


int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }
    
    BubbleSort(arr, 100);

    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}