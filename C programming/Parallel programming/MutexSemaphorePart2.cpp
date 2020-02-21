#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<Windows.h>
int  count;
int FLAG = 0;
HANDLE myMutex;
HANDLE mySemaphore1;
HANDLE mySemaphore2;
struct threadInfo
{
	HANDLE handle;
	DWORD id;
	int terminate;
};
struct item {
	int data;
	int empty = 1;
};
struct item *arr = (item*)malloc(count * sizeof(item));
DWORD WINAPI ProducersFunction(LPVOID lpParam)
{
	while (FLAG == 0)
	{
		WaitForSingleObject(mySemaphore1, INFINITE);
		for (int i = 0; i < count; i++)
		{
			WaitForSingleObject(myMutex, INFINITE);
			if (arr[i].empty == 1)
			{
				arr[i].empty = 0;
				arr[i].data = 25;
				ReleaseMutex(myMutex);
				ReleaseSemaphore(mySemaphore2, 1, NULL);
				break;
			}
			ReleaseMutex(myMutex);
		}
	}
	return 0;
}
DWORD WINAPI ConsumersFunction(LPVOID lpParam)
{
	while (FLAG == 0)
	{
		WaitForSingleObject(mySemaphore2, INFINITE);
		for (int i = 0; i < count; i++)
		{
			WaitForSingleObject(myMutex, INFINITE);
			if (arr[i].empty == 0)
			{
				arr[i].data = 0;
				arr[i].empty = 1;
				ReleaseMutex(myMutex);
				ReleaseSemaphore(mySemaphore1, 1, NULL);
				break;
			}
		}
		ReleaseMutex(myMutex);
	}
	return 0;
}
int main()
{
	int producer, consumer;
	printf("Enter count of elements of array: ");
	scanf_s("%d", &count);
	printf("Enter count of producer threads: ");
	scanf_s("%d", &producer);
	printf("Enter count of consumer threads: ");
	scanf_s("%d", &consumer);
	struct threadInfo *producers = (threadInfo*)malloc(producer * sizeof(struct threadInfo));
	struct threadInfo *consumers = (threadInfo*)malloc(consumer * sizeof(struct threadInfo));
	myMutex = CreateMutex(NULL, FALSE, NULL);
	mySemaphore1 = CreateSemaphore(NULL, 1, 4, NULL);
	mySemaphore2 = CreateSemaphore(NULL, 1, 4, NULL);
	for (int i = 0; i < consumer; i++)
	{
		(consumers + i)->id = i;
		(consumers + i)->handle = CreateThread(NULL, 0, ConsumersFunction, (LPVOID)consumers[i].id, 0, &consumers[i].id);
	}
	for (int i = 0; i < producer; i++)
	{
		(producers + i)->id = i;
		(producers + i)->handle = CreateThread(NULL, 0, ProducersFunction, (LPVOID)producers[i].id, 0, &producers[i].id);
	}
	int br;
	printf("Enter char for stop: ");
	scanf_s("%d", &br);
	while (br != 0)
	{
		scanf_s("%d", &br);
	}
	FLAG = 1;
	for (int i = 0; i < consumer; i++)
	{
		WaitForSingleObject((consumers + i)->handle, INFINITE);
	}
	for (int i = 0; i < producer; i++)
	{
		WaitForSingleObject((producers + i)->handle, INFINITE);
	}
	for (int i = 0; i < producer; i++)
	{
		CloseHandle((producers + i)->handle);
		printf("Producer ThreadID: %d\n", (producers + i)->id);
	}
	for (int i = 0; i < consumer; i++)
	{
		CloseHandle((consumers + i)->handle);
		printf("Consumer ThreadID: %d\n", (consumers + i)->id);
	}
	CloseHandle(myMutex);
	CloseHandle(mySemaphore1);
	CloseHandle(mySemaphore2);
	free(producers);
	free(consumers);
	free(arr);
	printf("Main thread with ID %d is terminated\n", GetCurrentThreadId());
	system("pause");
	return 0;
}