//when repetitions are not allowed
#include<stdio.h>
#include<conio.h>

int minRank(int);//to calculate min rank of a given number
int fact(int n);//to find factorial
int digitLength(int n);//to no. of digits in a given number
int tenthPower(int);

int main()
{
	int n;
	scanf_s("%d", &n);
	printf("minimum rank of %d is %d", n, minRank(n));
	_getch();
}
int minRank(int num)
{
	int i, j, d, d1, n1 = num, n2 = num, lengthOfDigit, minRank = 0, lesserNoBesforeIndex = 0, lesserNo = 0;
	lengthOfDigit = digitLength(num);

	for (i = 0; i < lengthOfDigit; i++)
	{
		d = n1 / tenthPower(lengthOfDigit - i - 1);

		for (j = lengthOfDigit - 1; j >= 0; j--)
		{
			d1 = n2 % 10;
			if (d>d1)
			{
				if (i>j)
					lesserNoBesforeIndex++;
				lesserNo++;
			}
			n2 = n2 / 10;
		}

		minRank = minRank + (lesserNo - lesserNoBesforeIndex)*fact(lengthOfDigit - 1 - i);
		n2 = num;
		n1 = n1%tenthPower(lengthOfDigit - i - 1);
		lesserNo = 0;
		lesserNoBesforeIndex = 0;
	}
	return minRank;
}
int fact(int n)
{
	int f = 1, i;
	for (i = 1; i <= n; i++)
		f = f*i;
	return f;
}
int digitLength(int n)
{
	int count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}
int tenthPower(int i)
{
	int j, n = 1;
	for (j = 1; j <= i; j++)
		n = n * 10;
	return n;
}