//Finding x power y modulo a
//enter x,y,a values
#include<stdio.h>
#include<conio.h>

int modulo(int, int, int);//to find modulo of given number
void findModuloOfMuliplesOf2(long int*, int, int);//to find the modulo of a for the powers of two 

int main(void)
{
	int a, x, y,mod;
	printf("enter values od x,y,a : ");
	scanf_s("%d%d%d", &x, &y, &a);
	mod = modulo(x, y, a);
	printf("\n%d^%d mod %d is %d",x,y,mod);
	_getch();
}
int modulo(int x, int y, int a)
{
	long int modOfPowersOf2[100];
	int i=0,d,m=0,y1=y,k=0;
	modOfPowersOf2[0] = x%y;
	while (y1 > 0)
	{
		d = y1 % 2;
		modOfPowersOf2[i+1] = (modOfPowersOf2[i] * modOfPowersOf2[i++]) % a;
		if (d != 0)
		{
			if (m == 0)
				m = modOfPowersOf2[i - 1];
			else
				m = (m%a*modOfPowersOf2[i - 1] % a) % a;
		}
		y1 = y1 / 2;
	}
		return m;
}