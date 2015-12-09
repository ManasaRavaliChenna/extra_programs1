#include<stdio.h>
#include<conio.h>
void findQAndCheckIfDivisibleBy11(char* p, int k, int len);
int length(char *);
int main()
{
	int len, k, intP;
	char p[100];

	printf("enter a numeric string , p ");
	gets_s(p);
	printf("enter no. of rep ,k ");
	scanf_s("%d", &k);

	len = length(p);
	findQAndCheckIfDivisibleBy11(p, k, len);
	_getch();
}
void findQAndCheckIfDivisibleBy11(char* p, int k, int len)
{
	long int d, sum = 0;
	int i, count = 0;
	char q[10000];
	while (count<len)
	{
		d = p[count] - '0';
		sum = sum + d;
		count++;
	}
	count = 0;

	while (count < k)
	{
		printf("%s", p);
		count++;
	}
	if (k*sum % 3 == 0)
		printf(" is divisible by 3");
	else
		printf(" is not divisible by 3 reminder is %d", k*sum % 3);
}
int length(char *a)
{
	long int i = 0;
	while (a[i] != '\0')
		i++;
	return i;
}