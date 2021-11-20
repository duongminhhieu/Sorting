﻿
#include "Header.h"



void selectionSort(int arr[], unsigned int n, double& running_time)
{
	clock_t start, end;
	start = clock();

	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}

	end = clock();
	running_time = ((double)(end - start)) / CLOCKS_PER_SEC;
}



void selectionSort_countComp(int arr[], int n, unsigned long int& count_comp)
{

	count_comp = 0;

	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0;++count_comp && i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1;++count_comp && j < n; j++)
			if (++ count_comp && arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}
}






// Xây dựng hàm Heap chất đống 
// Hàm có giá trị từ node i = largest của nó trờ xuống
void heapify(int* arr, int n, int i) {
	int largest = i; // phần tử đang xét
	int left = 2 * i + 1; // chỉ số bên trái 
	int right = 2 * i + 2; // chỉ số bên phải

	if (left < n && arr[largest] < arr[left]) {
		largest = left;
	}

	if (right < n && arr[largest] < arr[right]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}

}


void heapSort(int* arr, int n, double& running_time) {

	clock_t start, end;
	start = clock();

	// Duyệt từ node số gần cuối về 0
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	// Duyệt từ cuối về đầu để lấy các phần tử chỉ số 0 về cuối
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

	end = clock();
	running_time = ((double)(end - start)) / CLOCKS_PER_SEC;
}



void countingSort(int arr[], int n) {

	int* output = new int[n]; // The output will have sorted input array
	int max = arr[0];
	int min = arr[0];

	int i;
	for (i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i]; // Maximum value in array
		else if (arr[i] < min)
			min = arr[i]; // Minimum value in array
	}

	int k = max - min + 1; // Size of count array

	int* count_array = new int[k]; // Create a count_array to store count of each individual input value
	for (i = 0; i < k; i++)
		count_array[i] = 0;

	for (i = 0; i < n; i++)
		count_array[arr[i] - min]++; // Store count of each individual input value

	/* Change count_array so that count_array now contains actual
	 position of input values in output array */
	for (i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];

	// Populate output array using count_array and input array
	for (i = 0; i < n; i++)
	{
		output[count_array[arr[i] - min] - 1] = arr[i];
		count_array[arr[i] - min]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

}




