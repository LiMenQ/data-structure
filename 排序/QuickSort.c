#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partion1(int* arr, int left, int right){
    int key = left;
    while(left < right){
        while(left < right && arr[right] >= arr[key])
            right--;
        while(left < right && arr[left] <= arr[key])
            left++;
        swap(&arr[left], &arr[right]);
    }
    swap(&arr[key], &arr[left]);
    return left;
}

int Partion2(int* arr, int left, int right){
    int key = arr[left];
    int pit = left;
    while(left < right){
        while(left < right && arr[right] >= key) right--;
        swap(&arr[pit], &arr[right]);
        pit = right;
        while(left < right && arr[left] <= key) left++;
        swap(&arr[pit], &arr[left]);
        pit = left;
    }
    arr[pit] = key;
    return pit;
}

int Partion3(int* arr, int left, int right){
    int key = arr[left];
    int cur = left + 1, prev = left;
    while(cur <= right){
        if(arr[cur] < key && ++prev != cur){
            swap(&arr[prev], &arr[cur]);
        }
        cur++;
    }
    swap(&arr[left], &arr[prev]);
    return prev;
}

void _QuickSort(int* arr, int left, int right){
    if(left >= right) return;
    //int div = Partion1(arr, left, right);
    //int div = Partion2(arr, left, right);
    int div = Partion3(arr, left, right);
    _QuickSort(arr, left, div - 1);
    _QuickSort(arr, div + 1, right);
}

void QuickSort(int* arr, int left, int right){
    if(left >= right) return;
    int x = arr[left + right >> 1];
    int i = left - 1, j = right + 1;
    while(i < j){
        do i++; while(arr[i] < x);
        do j--; while(arr[j] > x);
        if(i < j) swap(&arr[i], &arr[j]);
    }
    QuickSort(arr, left, j);
    QuickSort(arr, j + 1, right);
}

int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }
    
    //_QuickSort(arr, 0, 99);
    QuickSort(arr, 0, 99);

    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}