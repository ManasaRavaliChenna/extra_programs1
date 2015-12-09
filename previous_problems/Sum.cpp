#include<stdio.h>
#include<conio.h>
void add(char *a, char *b, char *c);
int main(void)
{
	char c[1000], a[1000], b[1000];
	printf("enter two numbers :\n");
	gets_s(a);
	gets_s(b);
	add(a, b, c);
	_getch();
}
void add(char *a, char *b, char *c)
{
	int i, j = 0, d, k = 0, indexOfc = 1, flag = 1;
	for (i = 0; a[i] != '\0'; i++)
	{
		d = a[i] - '0' + b[i] - '0';
		c[indexOfc++] = char(d % 10 + '0');
		if (d > 9)
		{
			if (k == 0)
			{
				flag = 0;
				c[k] = '1';
			}
			else
				c[k] = c[k] + 1;
			k++;
			while (k <= i)
				c[k++] = '0';
		}
		else if (d<9)
			k = i + 1;
	}
	printf("sum is : ");
	for (int j = flag; j <= i; j++)
		printf("%c", c[j]);
}