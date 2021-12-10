#include "swap.h"
#include "bubbleSort.h"

void bubbleSort(int* arrPtr, int arrSize) {
	int iteration = 1;
	for(int u = 0; u < arrSize - 1; ++u){
		for (int u = 0, i = 0; i < arrSize - iteration; ++u, ++i) {
			if (arrPtr[u] > arrPtr[u + 1]) {
				swap(arrPtr, u, u + 1);
			}
		}
		++iteration;
	}
}