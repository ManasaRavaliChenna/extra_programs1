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
	long int d, sumE = 0, sumO = 0;
	int i, count = 0;
	char q[10000];
	while (count<len)
	{
		d = p[count] - '0';
		if (count % 2 == 0)
			sumE = sumE + d;
		else
			sumO = sumO + d;
		count++;
	}
	printf("\n%d %d\n", sumO, sumE);
	count = 0;
	while (count < k)
	{
		printf("%s", p);
		count++;
	}
	if (len % 2 == 1)
	{
		if ((sumE - sumO) % 11 == 0)
			printf(" divisible by 11");
		else if (k % 2 == 0)
			printf(" is divisible by 11");
		else
			printf(" is not divisible by 11");
	}
	else
	{
		if ((sumE - sumO) % 11 == 0)
			printf(" divisible by 11");
		else
			printf(" is not divisible by 11");
	}
}
int length(char *a)
{
	long int i = 0;
	while (a[i] != '\0')
		i++;
	return i;
}