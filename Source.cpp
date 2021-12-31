// Joe Epperson, IV
// Sorting Algorithm Speeds
// 10/11/2021
// The purpose of this program is to deduce the speed of some basic sorting algorithms based on the number of times values are moved within the respective arrays. This will be tested with three different arrays of 1000 values which will be filled with random values.

#include <iostream>
#include <array>
#include <random>
using namespace std;

int sortBubble(int* arr, int size);
int sortShell(int* arr, int n);
void swap(int& x, int& y);
int partition(int arr[], int low, int high, int& counterQuick);
void quickSort(int arr[], int low, int high, int& counterQuick);
void merge(int arr[], int l, int m, int r, int& counterMerge);
void mergeSort(int arr[], int l, int r, int& counterMerge);
int sortSelection(int* arr, int size);


int main()
{
	const int Size = 1000;
	int OriginalArrayOne[Size];
	int OriginalArrayTwo[Size];
	int OriginalArrayThree[Size];

	// Filling the arrays with values ranging from 0 to 4999
	for (int i = 0; i < Size; ++i)
	{
		int tempval = rand() % 5000;
		OriginalArrayOne[i] = tempval;
	}
	for (int i = 0; i < Size; ++i)
	{
		int tempval = rand() % 5000;
		OriginalArrayTwo[i] = tempval;
	}
	for (int i = 0; i < Size; ++i)
	{
		int tempval = rand() % 5000;
		OriginalArrayThree[i] = tempval;
	}

	

	//Declaring Variables for counters for later use in the output
	int counterBubbleOne = 0, counterBubbleTwo = 0, counterBubbleThree = 0;
	int counterShellOne = 0, counterShellTwo = 0, counterShellThree = 0;
	int counterQuickOne = 0, counterQuickTwo = 0, counterQuickThree = 0;
	int counterMergeOne = 0, counterMergeTwo = 0, counterMergeThree = 0;
	int counterSelectionOne = 0, counterSelectionTwo = 0, counterSelectionThree = 0;

	// Getting Values for ArrayOne
	int ArrayOne[Size];
	copy(begin(OriginalArrayOne), end(OriginalArrayOne), begin(ArrayOne));
	counterBubbleOne = sortBubble(ArrayOne, Size);
	copy(begin(OriginalArrayOne), end(OriginalArrayOne), begin(ArrayOne));
	counterShellOne = sortShell(ArrayOne, Size);
	copy(begin(OriginalArrayOne), end(OriginalArrayOne), begin(ArrayOne));
	quickSort(ArrayOne, 0, (Size - 1), counterQuickOne);
	copy(begin(OriginalArrayOne), end(OriginalArrayOne), begin(ArrayOne));
	mergeSort(ArrayOne, 0, (Size - 1), counterMergeOne);
	copy(begin(OriginalArrayOne), end(OriginalArrayOne), begin(ArrayOne));
	counterSelectionOne = sortSelection(ArrayOne, Size);

	// Getting Values for ArrayTwo
	int ArrayTwo[Size];
	copy(begin(OriginalArrayTwo), end(OriginalArrayTwo), begin(ArrayTwo));
	counterBubbleTwo = sortBubble(ArrayTwo, Size);
	copy(begin(OriginalArrayTwo), end(OriginalArrayTwo), begin(ArrayTwo));
	counterShellTwo = sortShell(ArrayTwo, Size);
	copy(begin(OriginalArrayTwo), end(OriginalArrayTwo), begin(ArrayTwo));
	quickSort(ArrayTwo, 0, (Size - 1), counterQuickTwo);
	copy(begin(OriginalArrayTwo), end(OriginalArrayTwo), begin(ArrayTwo));
	mergeSort(ArrayTwo, 0, (Size - 1), counterMergeTwo);
	copy(begin(OriginalArrayTwo), end(OriginalArrayTwo), begin(ArrayTwo));
	counterSelectionTwo = sortSelection(ArrayTwo, Size);

	// Getting Values for ArrayThree
	int ArrayThree[Size];
	copy(begin(OriginalArrayThree), end(OriginalArrayThree), begin(ArrayThree));
	counterBubbleThree = sortBubble(ArrayThree, Size);
	copy(begin(OriginalArrayThree), end(OriginalArrayThree), begin(ArrayThree));
	counterShellThree = sortShell(ArrayThree, Size);
	copy(begin(OriginalArrayThree), end(OriginalArrayThree), begin(ArrayThree));
	quickSort(ArrayThree, 0, (Size - 1), counterQuickThree);
	copy(begin(OriginalArrayThree), end(OriginalArrayThree), begin(ArrayThree));
	mergeSort(ArrayThree, 0, (Size - 1), counterMergeThree);
	copy(begin(OriginalArrayThree), end(OriginalArrayThree), begin(ArrayThree));
	counterSelectionThree = sortSelection(ArrayThree, Size);

	// Outputting values for all arrays and sorting algorithms
	cout << "Final Counter Values: Array One | Array Two | Array Three" << endl;
	cout << "         Bubble Sort: " << counterBubbleOne << "       " << counterBubbleTwo << "       " << counterBubbleThree << endl;
	cout << "          Shell Sort: " << counterShellOne << "         " << counterShellTwo << "         " << counterShellThree << endl;
	cout << "          Quick Sort: " << counterQuickOne << "         " << counterQuickTwo << "         " << counterQuickThree << endl;
	cout << "          Merge Sort: " << counterMergeOne << "         " << counterMergeTwo << "         " << counterMergeThree << endl;
	cout << "      Selection Sort: " << counterSelectionOne << "         " << counterSelectionTwo << "         " << counterSelectionThree << endl;

}


int sortBubble(int* arr, int size) 
{ 
	int counter = 0;

	for (int i = 0; i < (size - 1); i++) 
	{ 
		for (int j = 0; j < (size - i - 1); j++) 
		{ 
			if (arr[j] > arr[j + 1]) 
			{ 
				int temp = arr[j];
				arr[j] = arr[j + 1]; arr[j + 1] = temp;
				counter++;
			}
		}
	}
	return (counter);
}

int sortShell(int* arr, int n) 
{ 
	int counter = 0;

	for (int gap = n / 2; gap > 0; gap /= 2) 
	{ 
		for (int i = gap; i < n; i += 1) 
		{ 
			int temp = arr[i];
			int j;            
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
				counter++;
			}
			arr[j] = temp; 
			
		} 
	}
	return (counter);
}

void swap(int& x, int& y) 
{ 
	int temp = y;
	y = x;
	x = temp; 
}

int partition(int arr[], int low, int high, int& counterQuick)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element
	for (int j = low; j <= high - 1; j++)
	{        
		// If current element is smaller than the pivot        
		if (arr[j] < pivot)        
		{            
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
			counterQuick++;
		}    
	}    
	swap(arr[i + 1], arr[high]);
	counterQuick++;
	return (i + 1);
}

void quickSort(int arr[], int low, int high, int& counterQuick)
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high, counterQuick);
		quickSort(arr, low, pi - 1, counterQuick);
		quickSort(arr, pi + 1, high, counterQuick);
	} 
}

void merge(int arr[], int l, int m, int r, int& counterMerge) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	/* create temp arrays */
	int* L = new int[n1];
	int* R = new int[n2];
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	// Initial index of first subarray
	j = 0;
	// Initial index of second subarray
	k = l;
	// Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
			counterMerge++;
		} 
		else
		{
			arr[k] = R[j];
			j++;
			counterMerge++;
		}        
		k++;
	}    
	/* Copy the remaining elements of L[], if there     are any */
	while (i < n1)
	{ 
		arr[k] = L[i];
		i++;
		k++;
	}    
	/* Copy the remaining elements of R[], if there     are any */    
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int l, int r, int& counterMerge)
{ 
	if (l < r)
	{ 
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m, counterMerge);
		mergeSort(arr, m + 1, r, counterMerge);
		merge(arr, l, m, r, counterMerge);
	}
}

int sortSelection(int* arr, int size)
{ 
	int counter = 0;

	for (int i = 0; i < size - 1; i++)
	{ 
		int min = arr[i];
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minIndex = j;
				counter++;
			}
		}
		if (minIndex != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
			counter++;
		}
	}
	return (counter);
}
