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

void convert(int* a, int size, int* b) {

    for (size_t i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
}

int main() {
    double time;
    unsigned long long int count_comp = 0;
    int x = 2; // data order
    int n = 10000;
    int b[6] = { 10000,20000,50000,100000,300000,500000 }; // data size
    for (int i = 5; i < 6; i++)
    {
        n = b[i]; // data size
        cout << endl << n << endl;
        int* a = new int[n];
        int* tmp = new int[n];
        GenerateData(a, n, x);


        convert(a, n, tmp);
        cout << "\nSelection sort" << endl;
        clock_t start, end;
        start = clock();
        selectionSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;

        convert(a, n, tmp);
        count_comp = 0;
        //selectionSort_countComp(tmp,n, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nInsertion sort" << endl;
        start = clock();
        insertionSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        convert(a, n, tmp);
        count_comp = 0;
        insertionSort_countComp(tmp, n,count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nBubble sort" << endl;
        start = clock();
        bubbleSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        convert(a, n, tmp);
        count_comp = 0;
        //bubbleSortCountcomp(tmp, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nHeap sort" << endl;
        start = clock();
        heapSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        convert(a, n, tmp);
        count_comp = 0;
        heapSort_CountComp(tmp, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nMerge sort" << endl;
        start = clock();
        mergeSort(tmp, 0, n - 1);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl ;
        convert(a, n, tmp);
        count_comp = 0;
        mergeSort_countComp(tmp, 0, n - 1, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nQuick sort" << endl;
        start = clock();
        quickSort(tmp, 0, n - 1);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        convert(a, n, tmp);
        count_comp = 0;
        quickSortCountcomp(tmp, 0, n - 1, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nRadix sort" << endl;
        start = clock();
        //radixSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        convert(a, n, tmp);
        count_comp = 0;
        //radixSort_comp(tmp, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nShaker sort" << endl;
        start = clock();
        shakerSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        convert(a, n, tmp);
        count_comp = 0;
        shakerSortCountcomp(tmp, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nShell sort" << endl;
        start = clock();
        shellSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        convert(a, n, tmp);
        count_comp = 0;
        shellSort_countComp(tmp, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        convert(a, n, tmp);
        cout << "\nCounting sort" << endl;
        start = clock();
        countingSort(tmp, n);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000 << endl;
        convert(a, n, tmp);
        count_comp = 0;
        countingSort_CountComp(tmp, n, count_comp);
        cout << "comparision: " << count_comp << endl;
    }


    cout << endl << endl;
    system("pause");
}


