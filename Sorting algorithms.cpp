#include <iostream>
#include <cstdlib>
#include <chrono>

#include "Log.h"
#include "swap.h"
#include "selectionSort.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "shellSort.h"

int main() {
	srand(time(NULL));

	int size{ 0 };
	int choice{ 0 };
	bool display{ false };

	std::cout << "Enter array size:\n";
	std::cin >> size;
	int* Arr = new int[size];
	for (int digit=0, i = 0; i < size; ++i) {
		digit = rand() % 1000;
		Arr[i] = digit;
	}

	int firstIndex = 0, lastIndex = size-1;
	int arrSize = (lastIndex - firstIndex) + 1;

	std::cout << "Type 1 to show array, type 0 to not show(useful for large arrays):" << std::endl;
	std::cin >> display;
	if (display) { Log(Arr, arrSize); };
	std::cout << "\nChoose sorting algorithm:"
		<< "\n1.BubbleSort"
		<< "\n2.SelectionSort"
		<< "\n3.ShellSort"
		<< "\n4.QuickSort"
		<< "\n5.MergeSort\n";
	std::cin >> choice;

	std::chrono::steady_clock::time_point start;
	
	switch (choice){
	case 1:
		start = std::chrono::steady_clock::now();
		bubbleSort(Arr, arrSize);
		break;
	case 2:
		start = std::chrono::steady_clock::now();
		selectionSort(Arr, arrSize);
		break;
	case 3:
		start = std::chrono::steady_clock::now();
		shellSort(Arr, arrSize);
		break;
	case 4:
		start = std::chrono::steady_clock::now();
		quickSort(Arr, firstIndex, lastIndex);
		break;
	case 5:
		start = std::chrono::steady_clock::now();
		mergeSort(Arr, firstIndex, lastIndex);
		break;
	default:
		std::cout << choice << " is not an option";
		break;
	}		

	auto end = std::chrono::steady_clock::now();
	if (display) { Log(Arr, arrSize); };
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "\ntime: " << elapsed_seconds.count() << "s\n";

}
