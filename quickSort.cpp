#define pivotChoice 2			//Way of choosing pivot
								//1 - first; 2 - random; 3 - last

#include <cstdlib>

#include "swap.h"
#include "quickSort.h"

void quickSort(int* arrPtr, int firstIndex, int lastIndex) {
	if (lastIndex > firstIndex) {
		int pivotPos = qsPivot(arrPtr, firstIndex, lastIndex);
		quickSort(arrPtr, firstIndex, pivotPos - 1);
		quickSort(arrPtr, pivotPos + 1, lastIndex);
	}
}

int qsPivot(int* arrPtr, int firstIndex, int lastIndex) {
#if pivotChoice == 1
	int pivot = *(arrPtr + firstIndex);
#elif pivotChoice == 2
	int random = rand() % lastIndex;
	int pivot = *(arrPtr + random);
#elif pivotChoice == 3
	int pivot = *(arrPtr + lastIndex);
#endif
	int counter = firstIndex;

	for (int u = firstIndex + 1; u <= lastIndex; ++u) {
		if (pivot > arrPtr[u]) {
			++counter;
			swap(arrPtr, u, counter);
		}
	}
	swap(arrPtr, firstIndex, counter);

	return counter;
}