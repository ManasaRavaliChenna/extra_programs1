#include<stdio.h>
#include<conio.h>
void evaluate(int);
void display(int*, int);
int main()
{
	int n;
	printf("enter a number : ");
	scanf_s("%d", &n);
	evaluate(n);
	_getch();
}
void evaluate(int n)
{
	int num = n, v[100], index = 0, a, k = 0;
	if (n == 1)
		printf("1");
	else
	{
		while (n > 0)
		{
			if (n == 1)
			{
				v[index++] = 1;
				break;
				n = n / 4;
			}
			else
			{
				a = n;
				if (a % 2 != 0)
				{
					k = 1;
					a = a - 1;
				}
				if (a % 4 == 0)
				{
					a = a / 4;
					v[index++] = k;
					v[index++] = 0;
				}
				else
				{
					a = a / 4 + 1;
					v[index++] = 10 + k;
				}
			}
			n = a;
			k = 0;
		}
	}
	display(v, index);
}
void display(int a[], int n)
{
	printf("base -2 is : ");
	for (int i = n - 1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
}