#include<iostream>
#include<Windows.h>
#include<sysinfoapi.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct element {
	int Data;
	struct element* left;
	struct element* right;
};
typedef struct element Node;
int insert(Node* item, Node** root)
{
	if (*root == NULL) {
		*root = item;
		return 1;
	}
	if ((*root)->Data > item->Data)return insert(item, &(*root)->left);
	if ((*root)->Data < item->Data)return insert(item, &(*root)->right);
	else return 0;
}
void Print(Node* root, int k1, int k2)
{
	if (NULL == root)
		return;

	if (k1 < root->Data)
		Print(root->left, k1, k2);

	if (k1 <= root->Data && k2 >= root->Data)
		printf("%d ", root->Data);

	if (k2 > root->Data)
		Print(root->right, k1, k2);
}
int main()
{
	int buff = 10, t1, t2;
	Node* temp;
	Node* Tree = NULL;
	while (buff != 0)
	{
		scanf_s("%d", &buff);
		if (buff == 0)break;
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)break;
		temp->Data = buff;
		temp->left = NULL;
		temp->right = NULL;
		insert(temp, &Tree);
	}
	printf("\nvuvedete t1:");
	scanf_s("%d", &t1);
	printf("\nvuvedete t2:");
	scanf_s("%d", &t2);
	double before = GetTickCount64();
	Print(Tree, t1, t2);
	double after = GetTickCount64();
	printf("Execution time: %lf\n", (after - before) / 1000);
	system("pause");
	return 0;
}
