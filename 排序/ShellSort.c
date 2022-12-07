#include<stdio.h>
#include<stdlib.h>

void ShellSort(int* arr, int size){
    int gap = size;
    while(gap > 1){
        gap /= 2;
        for(int i = gap; i < size; i ++){
            int x = arr[i];
            int j = 0;
            for(j = i; j >= gap; j -= gap){
                if(arr[j - gap] > x)
                    arr[j] = arr[j - gap];
                else
                    break;
            }
            arr[j] = x;
        }
    }
}


int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }

    ShellSort(arr, 100);
    
    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}