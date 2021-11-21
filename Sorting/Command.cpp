#include"Command.h"
#include"Algorithms.h"
#include"DataGenerator.h"

string Mode[2] = { "-a","-c" };
string Algorithm_name[10] = { "selection-sort","insertion-sort","bubble sort","heap-sort","merge-sort","quick-sort","radix-sort","shaker-sort","shell-sort","counting-sort" };
string Input_order[4] = { "-rand","-sorted","-rev" ,"-nsorted" };
string Input_order2[4] = { "randomize","sorted","reverse sorted"," nearly sorted" };
string Output_parameters[3] = { "-time","-comp","-both" };

bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i]>9)
		{
			return false;
		}
	}
	return true;
}
int isMode(string mode)
{
	for (int i = 0; i < 2; i++)
	{
		if (mode == Mode[i])
		{
			return i;
		}
	}
	return -1;
}
int isAlgorithm_name(string algorithm)
{
	for (int i = 0; i < 10; i++)
	{
		if (algorithm == Algorithm_name[i])
		{
			return i;
		}
	}
	return -1;
}
int isInput_order(string input)
{
	for (int i = 0; i < 4; i++)
	{
		if (input == Input_order[i])
			return i;
	}
	return -1;
}
int isOutput_parameters(string output)
{
	for (int i = 0; i < 3; i++)
	{
		if (output == Output_parameters[i])
			return i;
	}
	return -1;
}
bool writeArrayToFile(string filename,int*a,int n)
{
	ofstream ofs(filename);
	if(!ofs.is_open())
	{
		return false;
	}
	ofs << n << endl;
	for (int i = 0; i < n; i++)
	{
		ofs << a[i] << " ";
	}
	ofs.close();
	return true;
}

bool chooseCommandType(int argc, char* argv[])
{
	int mode = isMode(argv[1]);
	if (mode == -1)
	{
		cout << "Lenh khong hop le" << endl;
		return false;
	}
	if (mode == 0)// mod thuat toan
	{
		if (argc == 6)
		{
			Command_2(argv);
		}
		else
		{
			if (isNumber(argv[3]))
			{
				//Command_3(argv);
			}
			else
			{
				Command_1(argv);
			}
		}
	}
	else//mode so sanh
	{
		if (argc == 5)
		{
			//Command_4(argv);
		}
		else
		{
			//Command_5(argv);
		}
	}
}
bool Command_1(char* argv[])
{
	int algorithm = isAlgorithm_name(argv[2]);
	if (algorithm == -1)
	{
		cout << "Lenh khong hop le" << endl;
		return false;
	}
	int output = isOutput_parameters(argv[4]);
	if (output == -1)
	{
		cout << "Lenh khong hop le" << endl;
		return false;
	}
	string filename = argv[3];
	ifstream ifs(filename);
	if (!ifs.is_open())
	{
		cout << "Khong the mo file" << endl;
		return false;
	}
	int n=0;
	ifs >> n;
	int* a = new int [n];
	for (int i = 0; i < n; i++)
	{
		ifs >> a[i];
	}
	ifs.close();
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Algorithm_name[algorithm] << endl;
	cout << "Input file: " << filename << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------------" << endl;
	double runtime;
	unsigned long long int count_comp = 0;
	clock_t start, end;
	switch (algorithm)
	{
	case 0:
		start = clock();
		selectionSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		selectionSort_countComp(a, n, count_comp);
		break;

	case 1:
		start = clock();
		insertionSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		insertionSort_countComp(a, n, count_comp);
		break;

	case 2:
		start = clock();
		bubbleSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		bubbleSortCountcomp(a, n, count_comp);
		break;
	case 3:
		start = clock();
		heapSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		heapSort_CountComp(a, n, count_comp);
		break;

	case 4:
		start = clock();
		mergeSort(a,0, n-1);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		mergeSort_countComp(a,0, n-1, count_comp);
		break;

	case 5:
		start = clock();
		quickSort(a, 0,n-1);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		quickSortCountcomp(a,0,n-1, count_comp);
		break;

	case 6:
		start = clock();
		radixSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		radixSort_comp(a, n, count_comp);
		break;

	case 7:
		start = clock();
		shakerSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		shakerSortCountcomp(a, n, count_comp);
		break;

	case 8:
		start = clock();
		shellSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		shellSort_countComp(a, n, count_comp);
		break;

	case 9:
		start = clock();
		countingSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		countingSort_CountComp(a, n, count_comp);
		break;
	default:
		break;
	}
	switch (output)
	{
	case 0:
		cout << "Running time: " << runtime << " ms"<<endl;
		break;
	case 1: 
		cout << "Comparisons: " << count_comp << endl;
		break;
	case 2:
		cout << "Running time: " << runtime << " ms" << endl;
		cout << "Comparisons: " << count_comp << endl;
		break;
	default:
		break;
	}
	writeArrayToFile("output.txt",a,n);

}
bool Command_2(char* argv[])
{
	int algorithm = isAlgorithm_name(argv[2]);
	if (algorithm == -1)
	{
		cout << "Lenh khong hop le" << endl;
		return false;
	}
	int inputoder = isInput_order(argv[4]);
	if (inputoder == -1)
	{
		cout << "Lenh khong hop le" << endl;
		return false;
	}
	int output = isOutput_parameters(argv[5]);
	if (output == -1)
	{
		cout << "Lenh khong hop le" << endl;
		return false;
	}
	int n = stoi(argv[3]);
	int* a = new int[n];
	GenerateData(a, n, inputoder);
	writeArrayToFile("input.txt",a,n);
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << Algorithm_name[algorithm] << endl;
	cout << "Input size: " << n << endl;
	cout << "Input order: " << Input_order2[inputoder] << endl;
	cout << "-------------------------------" << endl;
	double runtime;
	unsigned long long int count_comp = 0;
	clock_t start, end;
	switch (algorithm)
	{
	case 0:
		start = clock();
		selectionSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		selectionSort_countComp(a, n, count_comp);
		break;

	case 1:
		start = clock();
		insertionSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		insertionSort_countComp(a, n, count_comp);
		break;

	case 2:
		start = clock();
		bubbleSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		bubbleSortCountcomp(a, n, count_comp);
		break;
	case 3:
		start = clock();
		heapSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		heapSort_CountComp(a, n, count_comp);
		break;

	case 4:
		start = clock();
		mergeSort(a, 0, n - 1);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		mergeSort_countComp(a, 0, n - 1, count_comp);
		break;

	case 5:
		start = clock();
		quickSort(a, 0, n - 1);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		quickSortCountcomp(a, 0, n - 1, count_comp);
		break;

	case 6:
		start = clock();
		radixSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		radixSort_comp(a, n, count_comp);
		break;

	case 7:
		start = clock();
		shakerSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		shakerSortCountcomp(a, n, count_comp);
		break;

	case 8:
		start = clock();
		shellSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		shellSort_countComp(a, n, count_comp);
		break;

	case 9:
		start = clock();
		countingSort(a, n);
		end = clock();
		runtime = (double)(end - start) / CLOCKS_PER_SEC;
		runtime = runtime * 1000;
		count_comp = 0;
		countingSort_CountComp(a, n, count_comp);
		break;
	default:
		break;
	}
	switch (output)
	{
	case 0:
		cout << "Running time: " << runtime << " ms" << endl;
		break;
	case 1:
		cout << "Comparisons: " << count_comp << endl;
		break;
	case 2:
		cout << "Running time: " << runtime << " ms" << endl;
		cout << "Comparisons: " << count_comp << endl;
		break;
	default:
		break;
	}
	writeArrayToFile("output.txt", a, n);

}