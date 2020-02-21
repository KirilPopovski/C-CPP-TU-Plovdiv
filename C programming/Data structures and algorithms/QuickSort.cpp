#include <iostream>
#include<stdlib.h> 
#include<time.h> 
#include<stdio.h> 
#include<memory.h> 
#include<iostream>
#include<malloc.h> 
#include<Windows.h> 
void quicksort(int A[], int start, int stop)
{
	int i = start;
	int j = stop;
	int m, n;
	m = A[(start + stop) / 2];
	do
	{
		while (A[i] > m) i++;
		while (A[j] < m) j--;
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
int main()
{
	int n[5];
	n[0] = 10;
	n[1] = 15;
	n[2] = 12;
	n[3] = 7;
	n[4] = 18;
	quicksort(n, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		printf("\n%d", n[i]);
	}
}


