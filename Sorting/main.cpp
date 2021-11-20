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
    int x = 1;
    int n = 10000;
    int b[6] = { 10000,20000,50000,100000,300000,500000 };
    for (int i = 0; i < 6; i++)
    {
        n = b[i];
        cout << n << endl;
        int* a = new int[n];

        cout << "Selection sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;

        cout << "Insertion sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;

        cout << "Bubble sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        bubbleSort(a, n);
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        bubbleSortCountcomp(a, n, count_comp);
        cout << "comparision: " << count_comp << endl;

        cout << "Heap sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;

        cout << "Merge sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;


        cout << "Quick sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;


        cout << "Radix sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;

        cout << "Shaker sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;

        cout << "Shell sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;

        cout << "Counting sort" << endl;
        GenerateData(a, n, x);
        clock_t start, end;
        start = clock();
        //ham sort
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "time: " << time * 1000;
        GenerateData(a, n, x);
        count_comp = 0;
        //ham sort
        cout << "comparision: " << count_comp << endl;
    }
}