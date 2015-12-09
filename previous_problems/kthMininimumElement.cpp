#include<stdio.h>
#include<conio.h>
void findKthMinEle(int*, int*, int, int, int);
void findKthMinEleUsingSorting(int a[], int b[], int nOfA, int nOfB, int k);
void read(int a[], int b[], int n1, int n2);
void readArray(int a[], int n);
int main()
{
	int a[100], b[100], n1, n2, k, min;
	printf("enter no. ele in a");
	scanf_s("%d", &n1);
	printf("enter no. of ele in b");
	scanf_s("%d", &n2);
	printf("enter value of k : ");
	scanf_s("%d", &k);
	read(a, b, n1, n2);
	findKthMinEle(a, b, n1, n2, k);
	findKthMinEleUsingSorting(a, b, n1, n2, k);
	_getch();
}
void readArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
}
void read(int a[],int b[],int n1,int n2)
{
	printf("enter elements in a : ");
	readArray(a, n1);
	printf("enter elements in b : ");
	readArray(b, n2);
}
void findKthMinEle(int a[], int b[], int nOfA, int nOfB,int k)
{
	int i=0, j=0, count=0,min;
	if (k > (nOfA + nOfB))
	{
		printf("invalid input");
	}
	else if (k == 1)
	{
		if (a[i] < b[j])
			printf("%d is the %d min element", a[i], k);
		else
			printf("%d is the %d min element", b[j], k);
	}
	else if (k == nOfA + nOfB)
	{
		if (a[nOfA - 1]>b[nOfB - 1])
			printf("%d is the %d min element", a[nOfA - 1], k);
		else
			printf("%d is the %d min element", b[nOfB - 1], k);
	}
	else
	{
		while ((count < k) && (i<nOfA&&j<nOfB))
		{
			if (a[i] < b[j])
			{
				min = a[i];
				i++;
			}
			else if (b[j] < a[i])
			{
				min = b[j];
				j++;
			}
			else
			{
				min = a[i];
				i++;
				j++;
			}
			count++;
		}
		while ((i < nOfA) && (count<k))
		{
			min = a[i];
			i++;
			count++;
		}
		while ((j < nOfB) && (count<k))
		{
			min = b[j];
			j++;
			count++;
		}
		printf("%d is the %d min element", min, k);
	}
}
void findKthMinEleUsingSorting(int a[], int b[], int nOfA, int nOfB, int k)
{
	int i = 0, j = 0, l=0, min,c[100];
	if (k > (nOfA + nOfB))
	{
		printf("invalid input");
	}
	else if (k == 1)
	{
		if (a[i] < b[j])
			printf("%d is the %d min element", a[i], k);
		else
			printf("%d is the %d min element", b[j], k);
	}
	else if (k == nOfA + nOfB)
	{
		if (a[nOfA - 1]>b[nOfB - 1])
			printf("%d is the %d min element", a[nOfA - 1], k);
		else
			printf("%d is the %d min element", b[nOfB - 1], k);
	}
	else
	{
		while (i < nOfA&&j < nOfB)
		{
			if (a[i] < b[j])
			{
				c[l] = a[i];
				i++;
			}
			else if (b[j] < a[i])
			{
				c[l] = b[j];
				j++;
			}
			else
			{
				c[l] = a[i];
				i++;
				j++;
			}
			l++;
		}
		while (i < nOfA)
		{
			c[l++] = a[i++];
		}
		while (j < nOfB)
		{
			c[l++] = b[j++];
		}
		printf("%d is the %d min element", c[k-1], k);
	}
}
