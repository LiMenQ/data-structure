#include<stdio.h>
#include<stdlib.h>

void CountSort(int* arr, int size){
    int max = arr[0], min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int* count = (int*)calloc(range, sizeof(int));
    for(int i = 0; i < size; i++){
        count[arr[i] - min]++;
    }
    
    int j = 0;
    for(int i = 0; i < range; i++){
        while(count[i]--){
            arr[j++] = i + min;
        }
    }
}

int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }
    
    CountSort(arr, 100);

    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}