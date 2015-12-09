#include<stdio.h>
#include<conio.h>
int multiply(int a, int b);//to multiply
int add(int a, int b);//to add
int main()
{
	int a, b, prod;
	scanf_s("%d %d", &a, &b);
	prod = multiply(a, b);
	printf("%d", prod);
	_getch();
}
int multiply(int x, int y)
{
	int n1, n2, flag = 1, i, j, p = 0, c = 0;
	if (x == 0 || y == 0)
		return 0;
	else if (x == 1)
		return y;
	else if (y == 1)
		return x;
	else
	{
		if ((x < 0 && y>0) || (x > 0 && y < 0))
			flag = -1;
		if (x < 0)
			x = -x;
		if (y < 0)
			y = -y;
		while (y != 0)
		{
			if (y & 01)
			{
				printf("\n%d %d\n", y,p);
				//p = add(p, x);
				p = p + x;
			}
			x = x << 1;
			y = y >> 1; 
			printf("in1 %d %d \n", x, y);
		}
	}
	if (flag == -1)
		return -p;
	return p;
}
int add(int a, int b)
{
	if (b == 0)
	{
		printf("in2 %d ", a);
		return a;
	}
	else
	{
		printf("\nin %d %d\n", b, a);
		return(add(a^b, (a&b) >> 1));
	}
}