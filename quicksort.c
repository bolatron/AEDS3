#include <stdlib.h>
#include <stdio.h>
#include "quicksort.h"

/*
    QUICKSORT ALGORITHM
*/

int quickMerge(int *array, int start, int end) {
    int left, right, pivo, aux;
    right = end;
    left = start;
    pivo = array[start];
    while(left < right){
        while(array[left] <= pivo && left<end)
            left++;
        while(array[right] > pivo)
            right--;
        if(right < start || left > end)
            printf("Error!\n");
        if(left < right){
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
        }
    }
    array[start] = array[right];
    array[right] = pivo;
    return right;
}

void quickSort(int *array, int start, int end) {
    if(start < end){
        int pivo = quickMerge(array, start, end);
        quickSort(array, start, pivo-1, cont);
        quickSort(array, pivo+1, end, cont);
    }
}
