#include<stdio.h>
#include<stdlib.h>

void InsertSort(int* arr, int size){
    for(int i = 1; i < size; i++){ 
        int x = arr[i];
        int j = 0;
        for(j = i; j > 0; j--){
            if(arr[j - 1] > x) 
                arr[j] = arr[j - 1];
            else
                break;
        }
        arr[j] = x;
    }
}

int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }

    InsertSort(arr, 100);
    
    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}