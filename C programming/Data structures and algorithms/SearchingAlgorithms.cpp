

#include <iostream>
#include<stdlib.h> 
#include<time.h> 
#include<stdio.h> 
#include<memory.h> 
#include<malloc.h> 
#include<Windows.h> 

const int count = 1000;

void selection_sort(int A[], int n)
{
	int i, j, x, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j <= n - 1; j++)
			if (A[j] < A[min]) min = j;
		if (min != i)
		{
			x = A[min];
			A[min] = A[i];
			A[i] = x;
		}
	}
}

void insertion_sort(int A[], int n)
{
	int i, j, x;
	for (i = 1; i < n; i++)
	{
		x = A[i];
		j = i - 1;
		while (j >= 0 && x < A[j])
		{
			A[j + 1] = A[j];
			j--;
		}  
		A[j + 1] = x;
	}
}
void bubble_sort(int A[], int n)
{
	int i, j, x;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (A[j] < A[j - 1])
			{
				x = A[j];
				A[j] = A[j - 1];
				A[j - 1] = x;
			}
}
void bubble_sort_flag(int A[], int n)
{
	int i, x, flag;
	do
	{
		flag = 1;
		for (i = 0; i < n - 1; i++)
			if (A[i] > A[i + 1])
			{
				x = A[i];
				A[i] = A[i + 1];
				A[i + 1] = x;
				flag = 0;
			}
	} while (!flag);
}

void merge(int l, int m, int r, int A[])
{
	int i1 = l, j1 = m + 1, i2 = m, j2 = r;
	int k = l, n = r - l + 1;
	int* T = (int*)malloc(count * sizeof(int));
	while ((i1 <= i2) && (j1 <= j2))
	{
		if (A[i1] < A[j1])
		{
			T[k] = A[i1];
			i1++;
		}
		else
		{
			T[k] = A[j1];
			j1++;
		}
		k++;
	}
	while (i1 <= i2)
	{
		T[k] = A[i1];
		i1++;
		k++;
	}
	while (j1 <= j2)
	{
		T[k] = A[j1];
		j1++;
		k++;
	}
	for (k = 0; k < n; k++)
	{
		j1--;
		A[j1] = *(T+j1);
	}
}
void merge_sort(int l, int r, int A[])
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2;
		merge_sort(l, m, A);
		merge_sort(m + 1, r, A);
		merge(l, m, r, A);
	}
}

void quicksort(int A[], int start, int stop)
{
	int i = start;
	int j = stop;
	int m, n;
	m = A[(start + stop) / 2];
	do
	{
		while (A[i] < m) i++;
		while (A[j] > m) j--;
		if (i <= j)
		{
			n = A[i];
			A[i] = A[j];
			A[j] = n;
			i++; j--;
		}
	} while (i <= j);
	if (start < j)   quicksort(A, start, j);
	if (i < stop)   quicksort(A, i, stop);
}

void digitalSort(int A[], int lenght)
{
	int max = A[0];
	for (int i = 0; i < lenght; i++)
	{
		if (A[i] > max)max = A[i];
	}
	int* p = (int*)malloc((max + 1) * sizeof(int));
	for (int i = 0; i <= max; i++)
	{
		*(p+i) = 0;
	}
	for (int i = 0; i < lenght; i++)
	{
		p[A[i]]++;
	}
	int point = 0;
	for (int i = 0; i <= max; i++)
	{
		for (int j = 0; j < *(p+i); j++)
		{
			A[point] = i;
			point++;
		}
	}
}


int main()
{
	srand(time(NULL));
	int* p = (int*)malloc(count * sizeof(int));
	for (int i = 0; i < count; i++)
	{
		p[i] = rand() % count;
	}
	int* copy = nullptr;
	memcpy(copy, p, count * sizeof(int));
	int t1 = GetTickCount64();
	selection_sort(p, count);
	int t2 = GetTickCount64();
	memcpy(p, copy, count * sizeof(int));
	printf("Selection sort time: %d\n", t2 - t1);
	fflush(stdout);
	printf("Random print");
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", p[i]);
	}
	insertion_sort(p, count);
	int t3 = GetTickCount64();
	printf("Insertion sort time: %d\n", t3 - t2);
	memcpy(p, copy, count * sizeof(int));
	bubble_sort(p, count);
	int t4 = GetTickCount64();
	printf("Bubble sort time: %d\n", t4 - t3);
	memcpy(p, copy, count * sizeof(int));
	bubble_sort_flag(p, count);
	int t5 = GetTickCount64();
	printf("Bubble sort flag time: %d\n", t5 - t4);
	memcpy(p, copy, count * sizeof(int));
	merge_sort(0, count, p);
	int t6 = GetTickCount64();
	printf("Merge sort time: %d\n", t6 - t5);
	memcpy(p, copy, count * sizeof(int));
	quicksort(p, 0, count);
	int t7 = GetTickCount64();
	printf("Quick sort time: %d\n", t7 - t6);
	memcpy(p, copy, count * sizeof(int));
	digitalSort(p, count);
	int t8 = GetTickCount64();
	printf("Digital sort time: %d\n", t8 - t7);
	system("pause");
	return 0;
}
