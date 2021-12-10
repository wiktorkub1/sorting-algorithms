#include "swap.h"
#include "shellSort.h"

void shellSort(int* arrPtr, int arrSize) {
    for (int gapSize = arrSize / 2; gapSize > 0; gapSize /= 2)
    {
        for (int i = gapSize; i < arrSize; i += 1)
        {
            int tempArray = arrPtr[i];
            int j;
            for (j = i; j >= gapSize && arrPtr[j - gapSize] > tempArray; j -= gapSize) {
                arrPtr[j] = arrPtr[j - gapSize];
            }
            arrPtr[j] = tempArray;
        }
    }
}