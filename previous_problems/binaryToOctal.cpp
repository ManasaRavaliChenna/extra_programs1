#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void covertBinaryToOctal(char *b, int len);
int length(char *b);
int main()
{
	int len;
	char b[1000];
	printf("enter a binary number : ");
	gets_s(b);
	len = length(b);
	if (len>0)
	covertBinaryToOctal(b, len);
	_getch();
}
int length(char *b)
{
	int index = 0;
	while (b[index] != '\0')
	{
		if (b[index] >= '2'||b[index]<'0')
		{
			printf("invalid input");
			return -1;
		}
		index++;
	}
	return index;
}
void covertBinaryToOctal(char *b, int len)
{
	int d=0,k=1,lenOfo,indexOfo,indexOfb=0,flag=0,count=0;
	if (len == 1)
	{
		if (b[0] == '1')
			printf("1");
		else
			printf("0");
	}
	char *o;
	if (len % 3 == 0)
		lenOfo = len / 3;
	else
		lenOfo = len / 3 + 1;
	o = (char*)malloc((lenOfo)*sizeof(char));
	for (indexOfb = len-1,indexOfo=lenOfo-1; indexOfb >= 0; indexOfb-=3,indexOfo--)
	{
		while ((count < 3) && (indexOfb-count>=0))
		{
			d = d + (b[indexOfb - count] - '0')*k;
			k = k * 2;
			count++;
		}
		o[indexOfo] =char( d + '0');
		k = 1;
		d = 0;
		count = 0;
	}
	printf("octal no. is : ");
	for (int i = 0; i < lenOfo; i++)
		printf("%c", o[i]);
}