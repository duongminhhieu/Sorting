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

	int* a = new int[50000];
	double time;
	unsigned long int count;
	GenerateData(a, 50000, 0);
	//printArray(a, 100);

	//selectionSort_countComp(a, 500000,count);
	clock_t start, end;
	start = clock();
	countingSort(a, 50000);
	//cout << endl << "Compare: " << count << endl;
	end = clock();
	time = ((double)(end - start)) / CLOCKS_PER_SEC;
	//printArray(a, 100);
	cout << endl << "Time: " << time << endl;
	return 0;
}