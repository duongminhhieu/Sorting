
#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

void selectionSort(int arr[], unsigned int n);
void selectionSort_countComp(int arr[], int n, unsigned long int& count_comp);
void heapify(int* arr, int n, int i);
void heapSort(int* arr, int n);
void heapSort_CountComp(int* arr, int n, unsigned long long int& count_comp);
void heapify_CountComp(int* arr, int n, int i, unsigned long long int& count_comp);
void countingSort(int arr[], int n);
void countingSort_CountComp(int arr[], int n, unsigned long long int& count_comp);



void bubbleSort(int A[], int n);
int partition(int A[], int first, int last);
void quickSort(int A[], int first, int last);
void shakerSort(int A[], int n);
void bubbleSortCountcomp(int A[], int n, int& count_comp);
int partitionCountcomp(int A[], int first, int last, int& count_comp);
void quickSortCountcomp(int A[], int first, int last, int& count_comp);
void shakerSortCountcomp(int A[], int n, int& count_comp);


void insertionSort(int arr[], int n);
void insertionSort_countComp(int arr[], int n, int& count_comp);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void merge_countComp(int arr[], int l, int m, int r, int& count_comp);
void mergeSort_countComp(int arr[], int l, int r, int& count_comp);
void shellSort(int arr[], int n);
void shellSort_countComp(int arr[], int n, int& count_comp);

