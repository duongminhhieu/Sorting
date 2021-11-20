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



template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
