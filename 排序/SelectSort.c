#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectSort(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min]) 
                min = j;
        }
        swap(&arr[i], &arr[min]);
    }
}

int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }

    SelectSort(arr, 100);
    
    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}