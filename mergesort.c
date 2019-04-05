#include <stdio.h>
#include <stdlib.h>

#define SHIFT 1

// helper function for the Merge Sort
void PRmerge(int *array, int start, int middle, int end)
{
    int leftLength = middle - start + SHIFT;
    int rightLength = end - middle;

    // split array in half
    int *left = malloc(sizeof(int) * leftLength);
    int *right = malloc(sizeof(int) * rightLength);
    for (int i = 0; i < leftLength; i++) left[i] = array[start + i];
    for (int i = 0; i < rightLength; i++) right[i] = array[middle + 1 + i];

    // merging back in order
    int i = 0, j = 0, k = start;
    while (i < leftLength && j < rightLength) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    // merging remaining elements
    while (i < leftLength) {
        array[k] = left[i];
        i++; k++;
 
    }
    while (j < rightLength) {
        array[k] = right[j];
        j++; k++;
    }

    free(left); free(right);
}


// Merge Sort that is used to order the URLS by  their Page Rank
void PRmergeSort(int *array, int start, int end)
{
    if (start < end) {
        // same as (start + end)/2, but avoids overflow for large 
        // numbers
        int middle = start + (end - start)/2;
        // sort the two halves of the array
        PRmergeSort(array, start, middle);
        PRmergeSort(array, middle + SHIFT, end);
        // merge these sorted halves
        PRmerge(array, start, middle, end);

    }
}