#include "pch.h"
#include <stdio.h>
#include <conio.h>

// Povrh s stogom
int const MAX = 10;
int stack1[MAX], sp1 = -1;
int stack2[MAX], sp2 = -1;

void push(int array[], int &sp, int a)
{
	if (sp == (MAX - 1))
	{
		printf("Stack Overflow!\n");
		return;
	}
	sp++;
	array[sp] = a;
}

int pop(int array[], int &sp)
{
	if (sp == -1)
	{
		printf("Stack Undeflow\n");
		return -1;
	}
	int a = array[sp];
	array[sp] = 0;
	sp--;
	return a;
}

bool is_empty(int sp)
{
	if (sp == -1)
	{
		return true;
	}
	return false;
}

int PovrhStog(int a, int b) 
{	
	push(stack1, sp1, a);
	push(stack2, sp2, b);
	int povrh = 0;

	do
	{
		int n = pop(stack1, sp1);
		int m = pop(stack2, sp2);

		if (m == n || m == 0) povrh = povrh + 1;
		else
		{
			push(stack1, sp1, n - 1);
			push(stack2, sp2, m - 1);
			push(stack1, sp1, n - 1);
			push(stack2, sp2, m);
		}
	} while (!is_empty(sp1));
	return povrh;
}

// Povrh s rekurzijom
int Povrh(int n, int r)
{
	if (r == 0 || r == n) return 1;
	return Povrh(n - 1, r - 1) + Povrh(n - 1, r);
}


// MAIN
int main() 
{
	int n = 0, m = 0;
	printf("Unesite n: ");
	scanf_s("%d", &n);
	printf("Unesite m: ");
	scanf_s("%d", &m);

	printf("Povrh (rekurzija): %d\n", Povrh(n, m));
	printf("Povrh (stog): %d\n", PovrhStog(n, m));
	_getch();
	return 0;
}