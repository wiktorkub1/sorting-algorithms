#include "selectionSort.h"
#include "swap.h"

void selectionSort(int* arrPtr, int arrSize) {

	int minVal = *arrPtr;
	int position = 0;
	for (int k = 0; k < arrSize; ++k) {
		minVal = *(arrPtr+k);
		position = k;
		for (int u = k; u < arrSize; ++u) {
			if (minVal > arrPtr[u]) {
				minVal = arrPtr[u];
				position = u;
			}
		}
		swap(arrPtr, k, position);
	}
}