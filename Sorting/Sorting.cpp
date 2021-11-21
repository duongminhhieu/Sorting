#include "Algorithms.h"
#include "Command.h"
#include "DataGenerator.h"



void selectionSort(int arr[], unsigned int n)
{

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

}



void selectionSort_countComp(int arr[], int n, unsigned long long int& count_comp)
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


void heapSort(int* arr, int n) {

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

}

void heapify_CountComp(int* arr, int n, int i, unsigned long long int& count_comp) {
	int largest = i; // phần tử đang xét
	int left = 2 * i + 1; // chỉ số bên trái 
	int right = 2 * i + 2; // chỉ số bên phải

	if ((++count_comp && left < n) && (++count_comp && arr[largest] < arr[left])) {
		largest = left;
	}

	if ((++ count_comp && right < n) && ( ++count_comp && arr[largest] < arr[right])) {
		largest = right;
	}

	if ( ++count_comp && largest != i) {
		swap(arr[i], arr[largest]);
		heapify_CountComp(arr, n, largest,count_comp);
	}

}

void heapSort_CountComp(int* arr, int n, unsigned long long int& count_comp) {


	// Duyệt từ node số gần cuối về 0
	for (int i = n / 2 - 1;++count_comp && i >= 0; i--)
	{
		heapify_CountComp(arr, n, i,count_comp);
	}

	// Duyệt từ cuối về đầu để lấy các phần tử chỉ số 0 về cuối
	for (int i = n - 1; ++ count_comp && i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify_CountComp(arr, i, 0, count_comp);
	}

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


void countingSort_CountComp(int arr[], int n, unsigned long long int& count_comp) {

	count_comp = 0;

	int* output = new int[n]; // The output will have sorted input array
	int max = arr[0];
	int min = arr[0];

	int i;
	for (i = 1;++count_comp && i < n; i++)
	{
		if (++count_comp && arr[i] > max)
			max = arr[i]; // Maximum value in array
		else if (++count_comp && arr[i] < min)
			min = arr[i]; // Minimum value in array
	}

	int k = max - min + 1; // Size of count array

	int* count_array = new int[k]; // Create a count_array to store count of each individual input value
	for (i = 0; ++ count_comp && i < k; i++)
		count_array[i] = 0;

	for (i = 0; ++ count_comp && i < n; i++)
		count_array[arr[i] - min]++; // Store count of each individual input value

	/* Change count_array so that count_array now contains actual
	 position of input values in output array */
	for (i = 1; ++count_comp && i < k; i++)
		count_array[i] += count_array[i - 1];

	// Populate output array using count_array and input array
	for (i = 0;++count_comp && i < n; i++)
	{
		output[count_array[arr[i] - min] - 1] = arr[i];
		count_array[arr[i] - min]--;
	}

	for (i = 0; ++ count_comp && i < n; i++)
		arr[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

}




void bubbleSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
			}
		}
	}
}
int partition(int A[], int first, int last)
{
	//Chon 1 so random tu first den last
	srand(time(NULL));
	int random = first + rand() % (last - first);
	//doi vi tri random cho phan tu cuoi cung va lay phan tu do lam pivot
	swap(A[last], A[random]);
	int pivotindex = first;
	int pivot = A[last];
	for (int i = first; i <= last - 1; i++)
	{
		if (A[i] < pivot)
		{
			swap(A[pivotindex], A[i]);
			pivotindex++;
		}
	}
	swap(A[last], A[pivotindex]);
	return pivotindex;
}
void quickSort(int A[], int first, int last)
{
	if (first < last)
	{
		int pivotIndex = partition(A, first, last);
		quickSort(A, first, pivotIndex - 1);
		quickSort(A, pivotIndex + 1, last);
	}
}
void shakerSort(int A[], int n)
{
	int left = 0;
	int right = n - 1;
	int k = 0;
	do
	{
		for (int i = left; i < right; i++)
		{
			if (A[i] > A[i + 1])
			{
				swap(A[i], A[i + 1]);
				k = i;
			}
		}
		right = k;
		for (int i = right; i > left; i--)
		{
			if (A[i] < A[i - 1])
			{
				swap(A[i], A[i - 1]);
				k = i;
			}
		}
		left = k;
	} while (left < right);
}

void bubbleSortCountcomp(int A[], int n,unsigned long long int& count_comp)
{
	count_comp = 0;
	for (int i = 1; ++count_comp && i < n; i++)
	{
		for (int j = n - 1; ++count_comp && j >= i; j--)
		{
			if (++count_comp && A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
			}
		}
	}
}
int partitionCountcomp(int A[], int first, int last,unsigned long long int& count_comp)
{
	//Chon 1 so random tu first den last
	srand(time(NULL));
	int random = first + rand() % (last - first);
	//doi vi tri random cho phan tu cuoi cung va lay phan tu do lam pivot
	swap(A[last], A[random]);
	int pivotindex = first;
	int pivot = A[last];
	for (int i = first; ++count_comp && i <= last - 1; i++)
	{
		if (++count_comp && A[i] < pivot)
		{
			swap(A[pivotindex], A[i]);
			pivotindex++;
		}
	}
	swap(A[last], A[pivotindex]);
	return pivotindex;
}
void quickSortCountcomp(int A[], int first, int last,unsigned long long int& count_comp)
{
	if (++count_comp && first < last)
	{
		int pivotIndex = partitionCountcomp(A, first, last, count_comp);
		quickSortCountcomp(A, first, pivotIndex - 1, count_comp);
		quickSortCountcomp(A, pivotIndex + 1, last, count_comp);
	}
}
void shakerSortCountcomp(int A[], int n,unsigned long long int& count_comp)
{
	count_comp = 0;
	int left = 0;
	int right = n - 1;
	int k = 0;
	do
	{
		for (int i = left; ++count_comp && i < right; i++)
		{
			if (++count_comp && A[i] > A[i + 1])
			{
				swap(A[i], A[i + 1]);
				k = i;
			}
		}
		right = k;
		for (int i = right; ++count_comp && i > left; i--)
		{
			if (++count_comp && A[i] < A[i - 1])
			{
				swap(A[i], A[i - 1]);
				k = i;
			}
		}
		left = k;
	} while (++count_comp && left < right);
}






// Insertion Sort
void insertionSort(int arr[], int n) //no comparasion
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//-----------------------------------------------------------------------

// Merge Sort
// Gop 2 mang con arr[l...m] va arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//Tao cac mang tam
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy du lieu sang mang tam
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Gop 2 mang tam vao amng arr
	i = 0; // Khoi tao chi so bat dau cua mang con dau tien
	j = 0; // Khoi tao chi so bat dau cua mang con thu hai
	k = l; // Khoi tao chi so bat dau cua mang luu ket qua
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy cac phan tu con lai cua mang L vao arr neu co
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy cac phan tu con lai vao mang R vao arr neu co
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l la chi so trai va r la chi so phai cua mang can duoc sap xep
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Tuong tu (l+r)/2, nhung cach nay tranh tran so khi l va r lon
		int m = l + (r - l) / 2;

		// Goi ham de quy tiep tuc chia doi tung nua mang
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

//-----------------------------------------------------------------------

// Shell Sort
void shellSort(int arr[], int n)
{
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}



//Insertion Sort - Comparision
void insertionSort_countComp(int arr[], int n,unsigned long long int& count_comp)
{
	count_comp = 0;
	int i, key, j;
	for (i = 1; ++count_comp && i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while ((++count_comp && j >= 0) &&(++count_comp && arr[j] > key))
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//-----------------------------------------------------------------------

// Merge Sort - Comparision
// Gop 2 mang con arr[l...m] va arr[m+1..r]
void merge_countComp(int arr[], int l, int m, int r,unsigned long long int& count_comp)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	//Tao cac mang tam
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy du lieu sang mang tam
	for (i = 0; ++count_comp && i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; ++count_comp && j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Gop 2 mang tam vao amng arr
	i = 0; // Khoi tao chi so bat dau cua mang con dau tien
	j = 0; // Khoi tao chi so bat dau cua mang con thu hai
	k = l; // Khoi tao chi so bat dau cua mang luu ket qua
	while ((++count_comp && i < n1) && (++count_comp && j < n2))
	{
		if (++count_comp && L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy cac phan tu con lai cua mang L vao arr neu co
	while (++count_comp && i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy cac phan tu con lai vao mang R vao arr neu co
	while (++count_comp && j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l la chi so trai va r la chi so phai cua mang can duoc sap xep
void mergeSort_countComp(int arr[], int l, int r,unsigned long long int& count_comp)
{
	if (++count_comp && l < r)
	{
		// Tuong tu (l+r)/2, nhung cach nay tranh tran so khi l va r lon
		int m = l + (r - l) / 2;

		// Goi ham de quy tiep tuc chia doi tung nua mang
		mergeSort_countComp(arr, l, m, count_comp);
		mergeSort_countComp(arr, m + 1, r, count_comp);

		merge_countComp(arr, l, m, r, count_comp);
	}
}

//-----------------------------------------------------------------------

// Shell Sort - Comparision
void shellSort_countComp(int arr[], int n,unsigned long long int& count_comp)
{
	count_comp = 0;
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; ++count_comp && gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; ++count_comp && i < n; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct
			// location for a[i] is found
			int j;
			for (j = i;( ++count_comp && j >= gap) && (++count_comp && arr[j - gap] > temp); j -= gap)
			{
				arr[j] = arr[j - gap];
			}

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}

//-------------------------------------------------

//-------------------------------------------------
void radixSort(int* a, int n)
{
	int b[10], m = a[0], kn = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / kn > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / kn % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / kn % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		kn *= 10;
	}
}


void radixSort_comp(int* a, int n, unsigned long long int& count_comp) {
	int b[10], m = a[0], kn = 1;

	for (int i = 0;++count_comp && i < n; i++)
		if ( ++ count_comp && a[i] > m)
			m = a[i];

	while (++ count_comp && m / kn > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; ++count_comp && i < n; i++)
			bucket[a[i] / kn % 10]++;
		for (int i = 1; ++count_comp && i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; ++count_comp && i >= 0; i--)
			b[--bucket[a[i] / kn % 10]] = a[i];
		for (int i = 0; ++count_comp && i < n; i++)
			a[i] = b[i];
		kn *= 10;
	}
}

//-------------------------------------------------

//-------------------------------------------------
void flashSort(int a[], int n)
{
	int min = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}

	double c1 = (double)(m - 1) / (max - min);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - min));
		l[k]+=1;
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];

	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - min));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - min));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	insertionSort(a, n);
}
