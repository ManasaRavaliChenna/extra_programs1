#include<stdio.h>
#include<conio.h>
void winner(int *a,int adj,int,int);
int main()
{
	int adj,a[100],n,k;
	printf("enter no. of ele : ");
	scanf_s("%d", &n);
	printf("enter adj : ");
	scanf_s("%d", &adj);
	printf("Enter sequence i.e. 0 for continuous if not val >0");
	scanf_s("%d", &k);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	winner(a, adj,n,k);
	_getch();
}
void winner(int *a,int adj,int n,int k)
{
	int i , j,count=0,sum=0,max=0,win;
	/*for (i = 0; i < adj+k; i+=k)
		sum = sum + a[i];
	printf(" %d ", sum);
	win = adj / 2;*/
	for (i = 0; i <= k / 2; i++)
	{
		printf("sum : %d", sum);
		for (int l = i; l < adj + k + i; l += k)
			sum = sum + a[i];
		printf("\n%d\n", sum);
		if (sum > a[adj / 2 + k + i])
			win = a[adj / 2 + k + i];
		for (j = adj+i; j < n; j += k)
		{
			sum = sum - a[j - adj] + a[j];
			if (sum > max)
			{
				max = sum;
				win = (j - adj) + 1 + adj / 2;
				printf("\n%d", sum);
			}
		}
		sum = 0;
	}
	printf("\nWinner element is : %d pos is %d", a[win],win);
}