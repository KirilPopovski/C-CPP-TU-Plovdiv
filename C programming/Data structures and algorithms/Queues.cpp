#include "pch.h"
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
#include <tchar.h>
#include <strsafe.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
struct queue {
	int rank;
	char task[20];
	queue *next;
}*head = NULL;
queue* findPlace(int rank)
{
	queue *help = (queue *)malloc(sizeof(struct queue));
	help = head;
	if (!head)return NULL;
	else if (head->rank > rank)
		{
			return NULL;
		}
	else {
		while (help->next->rank < rank)
		{
			help = help->next;
			if (!help->next)
			{
				break;
			}
		}
		return help;
	}
}
int addelement(int rank, char *task)
{
	queue *ptr = (queue *)malloc(sizeof(struct queue));
	if (!ptr)
		return 0;
	ptr->rank = rank;
	strcpy_s(ptr->task, task);
	queue *ptr1 = findPlace(rank);
	if (!ptr1)
	{
		ptr->next = head;
		head = ptr;
	}
	else
	{
		ptr->next = ptr1->next;
		ptr1->next = ptr;
	}
	return 1;
}
void printTaskQueue()
{
	queue * ptr = head;
	while (ptr)
	{
		printf("%s, %d\n", ptr->task, ptr->rank);
		ptr = ptr->next;
	}
}int deleteQueue()
{
	if (!head)
	{
		return 0;
	}
	queue *ptr = head;
	queue *help;
	while (ptr->next)
	{
		help = ptr;
		ptr = ptr->next;
		printf("%d", help->rank);
		free(help);
	}
	return 1;
}
int main()
{
	int n;
	printf("Vavedete broq elementi");
	scanf_s("%d", &n);
	char task[20] = "tasks";
	int rank;
	for (int i = 0; i < n; i++)
	{
		printf("Vavedete rank: ");
		scanf_s("%d", &rank);
		addelement(rank, task);
	}
	printTaskQueue();
	deleteQueue();
	system("pause");
	return 0;
}
