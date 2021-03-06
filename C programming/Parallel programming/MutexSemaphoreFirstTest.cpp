#include"pch.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<Windows.h>
long a = 0;
int counter = 0;
int thrID;
int firstloop;
int secondloop;
HANDLE mySemaphor;
struct threadInfo
{
	HANDLE handle;
	DWORD id;
};
DWORD WINAPI myThreadFunction(LPVOID lpParam)
{
	printf("Thread started");
	for (int i = 0; i < firstloop; i++)
	{
		WaitForSingleObject(mySemaphor, INFINITE);
		thrID = (int)lpParam;
		for (int i = 0; i < secondloop; i++)
		{
			a++;
		}
		if (thrID != (int)lpParam)counter++;
		ReleaseSemaphore(mySemaphor,1,NULL);
	}
	printf("Thread %d terminated\n", (int)lpParam);
	return 0;
}
int main()
{
	int count;
	printf("Enter count of threads: ");
	scanf_s("%d", &count);
	printf("Enter count of first loop: ");
	scanf_s("%d", &firstloop);
	printf("Enter count of second loop: ");
	scanf_s("%d", &secondloop);
	struct threadInfo *example = (threadInfo*)malloc(count * sizeof(struct threadInfo));
	mySemaphor = CreateSemaphore(NULL,1,1, NULL);
	for (int i = 0; i < count; i++)
	{
		(example + i)->id = i;
		(example + i)->handle = CreateThread(NULL, 0, myThreadFunction, (LPVOID)example[i].id,CREATE_SUSPENDED , &example[i].id);
	}
	for (int i = 0; i < count; i++)
	{
		ResumeThread((example + i)->handle);
	}
	for (int i = 0; i < count; i++)
	{
		WaitForSingleObject((example + i)->handle, INFINITE);
	}
	for (int i = 0; i < count; i++)
	{
		CloseHandle((example + i)->handle);
		printf("ThreadID: %d\n", (example + i)->id);
	}
	CloseHandle(mySemaphor);
	printf("Main thread with ID %d is terminated\n", GetCurrentThreadId());
	printf("%d\n", a);
	printf("Count of unsyncronised accesses: %d", counter);
	system("pause");
	return 0;
}