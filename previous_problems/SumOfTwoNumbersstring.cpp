#include<stdio.h>
#include<conio.h>
int length(char *s);
int findSum(char *n1, char *n2,char *s, int len1, int len2);
int findStartingIndex(char *s);
int main(void)
{
	int i,len1, len2,len3=0,startIndexOfsum;
	char num1[100], num2[100], sum[101];
	gets_s(num1);
	gets_s(num2);
	len1 = length(num1);
	len2 = length(num2);
	startIndexOfsum=findSum(num1, num2, sum, len1, len2);
	printf("\n");
	if (len1 > len2)
		len3 = len1+1;
	else
		len3 = len2+1;
	for (i = startIndexOfsum; i < len3; i++)
		printf("%c", sum[i]);
	_getch();
	return 0;
}
int length(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
int findStartingIndex(char *s)
{
	int i=0;
	while (s[i] == '0')
		i++;
	return i;
}
int findSum(char *n1, char *n2, char *sum, int len1, int len2)
{
	int i,d, len3 = 0, j, k, st1, st2,st3,carry=0;
	st1 = findStartingIndex(n1);
	st2 = findStartingIndex(n2);
	if (len1 - st1 == 0)
	{
		sum = n2;
		return st2;
	}
	else if (len2-st2==0)
	{
		sum = n1;
		return st1;
	}
	else
	{
		if (len1 > len2)
		{
			len3 = len1 + 1;
			st3 = st1;
		}
		else
		{
			len3 = len2 + 1;
			st3 = st2;
		}
		i = len1 - 1;
		j = len2 - 1;
		k = len3 - 1;
		while (i >= st1 && j >= st2)
		{
			d = carry + (n1[i] - '0') + (n2[j] - '0');
			carry = d / 10;
			sum[k] = char((d % 10)+'0');
			k--;
			i--;
			j--;
		}
		while (i >= st1)
		{
			d = carry + (n1[i]-'0');
			carry = d / 10;
			sum[k] = char((d % 10) + '0');
			k--;
			i--;
		}
		while (j >= st2)
		{
			d = carry + (n2[j] - '0');
			carry = d / 10;
			sum[k] = char((d % 10) + '0');
			k--;
			j--;
		}
		if (carry == 1)
		{
			sum[0] = char(carry+'0');
		}
	}
	return st3;
}

