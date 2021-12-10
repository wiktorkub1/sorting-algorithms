#include "swap.h"

void swap(int* arrPtr, int firstEl, int secondEl) {		//funkcja zamieniajace ze soba
	if (firstEl != secondEl) {							//dwa elementy tablicy
		int buffer = arrPtr[firstEl];
		arrPtr[firstEl] = arrPtr[secondEl];
		arrPtr[secondEl] = buffer;
	}
}