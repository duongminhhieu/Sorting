#include<iostream>
#include<stdio.h>
#include<time.h>
#include "Algorithms.h"
#include "Command.h"
#include "DataGenerator.h"


// Function to print an array
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}


int main() {
    double time;
    unsigned long long int count_comp = 0;
    int x = 1;
    int n = 10000;
    int b[6] = { 10000,20000,50000,100000,300000,500000 };
    for (int i = 0; i < 6; i++)
    {
        n = b[i];
        cout << n << endl;
        int* a = new int[n];

        cout << "\nSelection sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        selectionSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        selectionSort_countComp(a,n, count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "\nInsertion sort" << endl;
        GenerateData(a, n, x);
 
        start = clock();
        insertionSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        insertionSort_countComp(a, n,count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "\nBubble sort" << endl;
        GenerateData(a, n, x);

        start = clock();
        bubbleSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        bubbleSortCountcomp(a, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "\nHeap sort" << endl;
        GenerateData(a, n, x);

        start = clock();
        heapSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        heapSort_CountComp(a, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "\nMerge sort" << endl;
        GenerateData(a, n, x);

        start = clock();
        mergeSort(a, 0, n - 1);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl ;
        GenerateData(a, n, x);
        count_comp = 0;
        mergeSort_countComp(a, 0, n - 1, count_comp);
        cout << "comparision: " << count_comp << endl;


        cout << "\nQuick sort" << endl;
        GenerateData(a, n, x);

        start = clock();
        quickSort(a, 0, n - 1);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        quickSortCountcomp(a, 0, n - 1, count_comp);
        cout << "comparision: " << count_comp << endl;


        cout << "\nRadix sort" << endl;
        GenerateData(a, n, x);

        start = clock();
        //radixSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        //radixSort_comp(a, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "\nShaker sort" << endl;
        GenerateData(a, n, x);

        start = clock();
        shakerSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        shakerSortCountcomp(a, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "\nShell sort" << endl;
        GenerateData(a, n, x);
   
        start = clock();
        shellSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        shellSort_countComp(a, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "\nCounting sort" << endl;
        GenerateData(a, n, x);

        start = clock();
        countingSort(a, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        GenerateData(a, n, x);
        count_comp = 0;
        countingSort_CountComp(a, n, count_comp);
        cout << "comparision: " << count_comp << endl;
    }


    cout << endl << endl;
    system("pause");
}


