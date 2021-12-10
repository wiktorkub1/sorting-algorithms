#include "swap.h"
#include "mergeSort.h"

#include <iostream>

void mergeSort(int* arrPtr, int firstIndex, int lastIndex) {
	if (firstIndex < lastIndex) {
		int middleIndex = (firstIndex + lastIndex) / 2;
		mergeSort(arrPtr, firstIndex, middleIndex);
		mergeSort(arrPtr, middleIndex + 1, lastIndex);
		merge(arrPtr, firstIndex, middleIndex, lastIndex);
	}
}

void merge(int* arrPtr, int firstIndex, int middleIndex, int lastIndex) {
	int arrSize = lastIndex - firstIndex + 1;
	int* buffArray = new int[arrSize];

	int lowIndex = firstIndex;
	int highIndex = middleIndex + 1;
	int properIndex = 0;

	while (lowIndex<=middleIndex && highIndex<=lastIndex) {
		if (arrPtr[lowIndex] <= arrPtr[highIndex]) {
			buffArray[properIndex] = arrPtr[lowIndex];
			++lowIndex;
		}
		else {
			buffArray[properIndex] = arrPtr[highIndex];
			++highIndex;
		}
		++properIndex;
	}

	while (lowIndex <= middleIndex) {
		buffArray[properIndex] = arrPtr[lowIndex];
		++lowIndex;
		++properIndex;
	}

	while (highIndex <= lastIndex) {
		buffArray[properIndex] = arrPtr[highIndex];
		++highIndex;
		++properIndex;
	}

	for (int u = 0; u < arrSize; ++u) {
		arrPtr[firstIndex + u] = buffArray[u];
	}

	delete[] buffArray;
}