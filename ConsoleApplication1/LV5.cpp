#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void heapify(int *V, int n, int i);
void merge(int *V, int left_index, int m, int right_index);

void heap_sort(int *V, int n);
void bubble_sort(int *V, int n);
void merge_sort(int *V, int left_index, int right_index);

int main()
{
	int arr1[] = { 12, 11, 13, 5, 6, 7 };
	int arr2[] = { 12, 11, 13, 5, 6, 7 };
	int arr3[] = { 12, 11, 13, 5, 6, 7 };

	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int n3 = sizeof(arr3) / sizeof(arr3[0]);

	//heap_sort(arr1, n1);
	//bubble_sort(arr2, n2);
	merge_sort(arr3, 0, n3 - 1);

	printf("Sortirano polje (Heapsort): \n");
	for (int i = 0; i < n1; i++)
	{
		printf("%d\n", *(arr1 + i));
	}

	printf("\nSortirano polje (Bubble Sort): \n");
	for (int i = 0; i < n2; i++)
	{
		printf("%d\n", *(arr2 + i));
	}

	printf("\nSortirano polje (Merge Sort): \n");
	for (int i = 0; i < n3; i++)
	{
		printf("%d\n", *(arr3 + i));
	}
	return 0;
}

// Heapsort Algorithm
void heapify(int *V, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && *(V + left) > *(V + largest))
	{
		largest = left;
	}

	if (right < n && *(V + right) > *(V + largest))
	{
		largest = right;
	}

	if (largest != i)
	{
		swap((V + i), (V + largest));
		heapify(V, n, largest);
	}
}

void heap_sort(int *V, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(V, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(V, (V + i));
		heapify(V, i, 0);
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// Bubble Sort Algorithm
void bubble_sort(int *V, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (*(V + j) > *(V + j + 1))
			{
				swap((V + j), (V + j + 1));
			}
		}
	}
}

// Merge Sort Algorithm
void merge(int *V, int left_index, int m, int right_index)
{
	int n1 = m - left_index + 1;
	int n2 = right_index - m;

	int *left = (int *)malloc(sizeof(int) * n1);
	int *right = (int *)malloc(sizeof(int) * n2);

	for (int i = 0; i < n1; i++)
	{
		*(left + i) = *(V + left_index + i);
	}
	for (int j = 0; j < n2; j++)
	{
		*(right + j) = *(V + m + 1 + j);
	}

	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2)
	{
		if (*(left + i) <= *(right + j))
		{
			*(V + k) = *(left + i);
			i++;
		}
		else
		{
			*(V + k) = *(right + j);
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		*(V + k) = *(left + i);
		i++;
		k++;
	}
	while (j < n2)
	{
		*(V + k) = *(right + j);
		j++;
		k++;
	}
}

void merge_sort(int *V, int left_index, int right_index)
{
	if (left_index < right_index)
	{
		int m = left_index + (right_index - 1) / 2;
		merge_sort(V, left_index, m);
		merge_sort(V, m + 1, right_index);
		merge(V, left_index, m, right_index);
	}
}
