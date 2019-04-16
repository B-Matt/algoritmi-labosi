#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
	char x;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(char data)
{
	struct Node* t = (struct Node*) malloc(sizeof(Node));
	t->x = data;
	t->left = t->right = NULL;
	return t;
}

struct Node* insertNode(struct Node* node, char data)
{
	if (node == NULL)
	{
		return newNode(data);
	}

	if (data < node->x)
	{
		node->left = insertNode(node->left, data);
	}
	else if (data > node->x)
	{
		node->right = insertNode(node->right, data);
	}
	return node;
}

struct Node* createTree(char data[], int size, struct Node* head)
{
	for (int i = 0; i < size - 1; i++)
	{
		head = insertNode(head, data[i]);
	}	
	return head;
}

// OBILAZAK STABLA
void preOrder(struct Node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->x);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(struct Node* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->left);
	printf("%c", root->x);
	inOrder(root->right);
}

void postOrder(struct Node* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%c", root->x);
}

// MAIN
int main()
{
	char data[] = { "data" };
	struct Node* head = NULL;
	head = createTree(data, sizeof(data), head);

	printf("Preorder: ");
	preOrder(head);
	printf("\nInorder: ");
	inOrder(head);
	printf("\nPostorder: ");
	postOrder(head);
	_getch();
	return 0;
}