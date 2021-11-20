

#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

void selectionSort(int arr[], unsigned int n, double& running_time);
void selectionSort_countComp(int arr[], int n, unsigned long int& count_comp);
void heapify(int* arr, int n, int i);
void heapSort(int* arr, int n, double& running_time);
void countingSort(int arr[], int n);

void bubbleSort(int A[], int n);
int partition(int A[], int first, int last);
void quickSort(int A[], int first, int last);
void shakerSort(int A[], int n);
void bubbleSortCountcomp(int A[], int n, int& count_comp);
int partitionCountcomp(int A[], int first, int last, int& count_comp);
void quickSortCountcomp(int A[], int first, int last, int& count_comp);
void shakerSortCountcomp(int A[], int n, int& count_comp);
