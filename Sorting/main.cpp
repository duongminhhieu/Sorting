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

    int count_comp = 0;
    int n = 10000;
    int* a = new int[n];

    cout << "Selection sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;

    cout << "Insertion sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;

    cout << "Bubble sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    bubbleSort(a, n);
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    bubbleSortCountcomp(a, n, count_comp);
    cout << "comparision: " << count_comp << endl;

    cout << "Heap sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;

    cout << "Merge sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;


    cout << "Quick sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;


    cout << "Radix sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;

    cout << "Shaker sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;

    cout << "Shell sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;

    cout << "Counting sort" << endl;
    GenerateData(a, n, 1);
    clock_t start, end;
    start = clock();
    //ham sort
    end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "time: " << time * 1000;
    GenerateData(a, n, 1);
    count_comp = 0;
    //ham sort
    cout << "comparision: " << count_comp << endl;
}