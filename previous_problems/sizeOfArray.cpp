#include<stdio.h>
#include<conio.h>
void evaluate(int a[],int *n);
int main()
{
	int a[10000];
	int n,i=0;
	printf("enter elements in an array and enter -1 to stop input :\n ");
	scanf_s("%d", &a[i++]);
	while (a[i-1] != -1)
		scanf_s("%d",&a[i++]);
	evaluate(a, &n);
	printf("\n size of array is %d", n+1);
	_getch();
}
void evaluate(int a[], int *n)
{
	int powOf2=1,i=1;
	while (1)
	{
		if (a[i - 1] < a[i] && a[i] < a[i + 1])
		{
			powOf2 = powOf2 * 2;
			i = powOf2 ;
		}
		else if (a[i] == 0)
		{
			if (a[i - 1] > 0)
			{
				if (a[i - 1] < a[i - 2])
					*n = i - 3;					
				else
					*n = i - 2;
				return;
			}
			else
				break;
		}	
		else
		{
			if (a[i + 1] == 0)
				*n = i - 2;
			else
				*n = i - 1;
			return;
		}
	}
	while (1)
	{
		if (a[i] == 0)
		{
			powOf2 = powOf2 / 2;
			i = i - powOf2 / 2;
		}
		else if (a[i - 1] < a[i] && a[i] < a[i + 1])
		{
			powOf2 = powOf2 / 2;
			i = i + powOf2;
		}
		else
		{
			*n = i - 2;
			return;
		}
	}
}