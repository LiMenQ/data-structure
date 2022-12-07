#include<stdio.h>
#include<stdlib.h>

void MergeSortNonR(int* arr, int size){
    int* tmp = (int*)malloc(sizeof(int) * size);
    int gap = 1;
    while(gap < size){
        for(int i = 0; i <= size; i += 2 * gap){

            int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (end1 >= size || begin2 >= size) {
				break;
			}
			if (end2 >= size) {
				end2 = size - 1;
			}

            int j = i;
			while (begin1 <= end1 && begin2 <= end2) {
				if (arr[begin1] <= arr[begin2]) {
					tmp[j++] = arr[begin1++];
				}
				else {
					tmp[j++] = arr[begin2++];
				}
			}

			while (begin1 <= end1) {
				tmp[j++] = arr[begin1++];
			}

			while (begin2 <= end2) {
				tmp[j++] = arr[begin2++];
			}

			for (int k = i; k <= end2; k++) {
				arr[k] = tmp[k];
			}
        }
        gap *= 2;
    }
}

void _MergeSort(int* arr, int left, int right, int* tmp){
    if(left >= right) return;
    int mid = left + right >> 1;
    _MergeSort(arr, left, mid, tmp);
    _MergeSort(arr, mid + 1, right, tmp);

    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int i = left;
    while(begin1 <= end1 && begin2 <= end2){
        if(arr[begin1] < arr[begin2]){
            tmp[i++] = arr[begin1++];
        }else{
            tmp[i++] = arr[begin2++];
        }
    }

    while(begin1 <= end1){
        tmp[i++] = arr[begin1++];
    }
    
    while(begin2 <= end2){
        tmp[i++] = arr[begin2++];
    }

    for(int j = left; j <= right; j++){
        arr[j] = tmp[j];
    }
}


void MergeSort(int* arr, int size){
    int* tmp = (int*)malloc(sizeof(int) * size);
    _MergeSort(arr, 0, size - 1, tmp);
}


int main(){

    int arr[100] = {0};

    for(int i = 0; i < 100; i++){
        arr[i] = rand() % 100;
    }
    
    //MergeSort(arr, 100);
    MergeSortNonR(arr, 100);

    for(int i = 0; i < 100; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}