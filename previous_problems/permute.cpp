#include<stdio.h>
#include<conio.h>
void permute(int a[], int i, int j,long int*,long int*);
void swap(int *i, int *j);
void swap(long int *i,long int *j);
void intoArray(int a[],long int num);
void display(long int v[]);
void display(int v[]);
long int toInteger(int *);
void bubble(int *);
void bubble(long int *);
static long int in=0;
int main()
{
	long int num, p[40320], indexOfp = 0;
	int a[8];
	printf("enter a 8 digit no : ");
	scanf_s("%d", &num);
	intoArray(a, num);
	permute(a, 0, 7, p, &indexOfp);
	bubble(p);
	display(p);
	_getch();
}
void display(long int a[])
{
	for (int i = 0; i < 40320; i++)
		printf("%ld\n", a[i]);
}
void intoArray(int a[],long int num)
{
	int i=0;
	while (num > 0)
	{
		a[i++] = num % 10;
		num = num / 10;
	}
	bubble(a);
}
void bubble(int a[])
{
	int i = 0, flag = 1;
	while (flag == 1)
	{
		flag=0;
		for (int i = 0; i < 7; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
	}
}
void bubble(long int a[])
{
	int i = 0, flag = 1;
	while (flag == 1)
	{
		flag = 0;
		for (int i = 0; i < 40319; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
	}
}
void display(int a[])
{
	for (int i = 0; i < 8; i++)
		printf("%d", a[i]);
	printf("\n");
}
void permute(int a[], int i, int j,long int p[],long int *indexOfp)
{
	if (i == j)
		p[in++]=toInteger(a);
	else
	{
		for (int k = i; k <= j; k++)
		{
			swap(&a[k], &a[i]);
			permute(a, i + 1, j, p,indexOfp);
			swap(&a[k], &a[i]);
		}
	}
}
long int toInteger(int a[])
{
	int i = 7;
	long int num = 0;
	while (i >= 0)
		num = num * 10 + a[i--];
	return num;
}
void swap(int *i, int *j)
{
	int c = *i;
	*i = *j;
	*j = c;
}
void swap(long int *i, long int *j)
{
	int c = *i;
	*i = *j;
	*j = c;
}