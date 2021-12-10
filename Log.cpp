#include "Log.h"
#include <iostream>

void Log(int* arrPtr, int arrSize) {					//funkcja wyswietlajaca zawartosc tablicy
	for (int u = 0; u < arrSize; ++u) {
		std::cout << (*arrPtr++) << " ";
	}
	std::cout << std::endl;
}