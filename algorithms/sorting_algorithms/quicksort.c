#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 * 1) pick an element, called a pivot from the array
 * 2) partition
 */

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int calculatePivot(int low, int high) {
    return (low + (high - low) / 2);
}

void quickSort(int arr[], int low, int high) {
    int pivot = arr[calculatePivot(low, high)];

    int i = low, j = high;
    while (i <= j) {
        // All elements to the left of the pivot must be
        // smaller than the pivot.
        while (arr[i] < pivot) {
            i++;
        }
        
        // All elements to the right of the pivot must be
        // larger than the pivot
        while (arr[j] > pivot)  {
            j--;
        }

        if (i <= j) {
            swap(arr, i, j);
            i++;
            j--;
        }

        if (low < j) {
            quickSort(arr, low, j);
        }
        if (i < high) {
            quickSort(arr, i, high);
        }
    }
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int arr[] = {
        1,11,2,45,1,87,3,54,2,44,100,
        478,33,97,322,3,4,5,9,7,4,
        898,287,538,666,143,490,557,56,91,822,
        943,721,403,237,207,486,159,348,713,235,
        570,627,836,413,87,168,363,672,642,909,
        844,927,924,821,861,999,238,576,832,963,501,
        543,46,948,100,863,562,803,590,455
    };
    int len = (int)sizeof(arr)/sizeof(arr[0]);
    printArr(arr, len);
    quickSort(arr, 0, len - 1);
    printArr(arr, len);
    return 0;
}