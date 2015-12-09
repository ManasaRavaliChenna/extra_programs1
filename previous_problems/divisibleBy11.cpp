#include<stdio.h>
#include<conio.h>
int checkDivisiblityBy11(char*,int,int);
void checkDivisiblityBy11_1(char*, int, int);
int length(char*,int*);
int main()
{
	int len,rem,firstNonZeroIndex;
	char a[10000];
	printf("enter a numeric string : ");
	gets_s(a);
	len = length(a,&firstNonZeroIndex);
	rem=checkDivisiblityBy11(a, len,firstNonZeroIndex);
	if (rem == 0)
		printf("%s is divisible by 11", a);
	else
		printf("%s is not divisible rem is %d", a, rem);
	checkDivisiblityBy11_1(a, len, firstNonZeroIndex);
	_getch();
}
int length(char *a,int *s)
{
	int count = 0, i = 0;
	while (a[i] == '0'&&a[i] != '\0')
		i++;
	*s = i;
	while (a[i] != '\0')
		i++;
	return i;
}
int checkDivisiblityBy11(char *a, int len,int st)
{
	int rem=0,d,i=st+2,base='0';
	if (len-st == 0)//when string is 0
		return 0;
	else if (len-st == 1)
		return a[st];
	else
	{
		rem = ((int(a[st]) - base) * 10 + ((int)(a[st+1]) - base)) % 11;
		while (i < len)
		{
			d = int(a[i]) - base;
			rem = (rem * 10 + d) % 11;
			i++;
		}
		return rem;
	}
}
void checkDivisiblityBy11_1(char *p, int len, int st)
{
	long int d, sumE = 0, sumO = 0;
	int i, count = st;
	char q[10000];
	while (count < len)
	{
		d = p[count] - '0';
		if (count % 2 == 0)
			sumE = sumE + d;
		else
			sumO = sumO + d;
		count++;
	}
	count = 0;
	if ((sumE - sumO) % 11 == 0)
		printf("\n%s divisible by 11",p);
	else
		printf("\n%s is not divisible by 11",p);
}
