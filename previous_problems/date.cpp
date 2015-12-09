#include<stdio.h>
#include<conio.h>
void getValues(char*, int*, int*, int*);//to get values of date,month,year from dd/mm/year 
void checkDate(int, int, int); //checks if the given date is vaalid
void convertMonth(int mon);//displays month in string format
void convertDate(int d, int, int);//displays date instring format
void convertYear(int yr);//displays year instring format
void printOnesDigit(int);//displays digit in ones place with th nd st
void printTensDigit(int);//displays digit in tens place 
void printOnesDigit1(int d);//displays digit in ones place
void format(int);//to display date in given format
void printDigit(int);
int main(void)
{
	int date, mon, yr;
	char d[12];
	printf("enter date ");
	gets_s(d);
	getValues(d, &date, &mon, &yr);
	checkDate(date, mon, yr);
	convertMonth(mon);
	convertYear(yr);
	_getch();
}
void getValues(char* d, int *dd, int *mon, int *y)
{
	int dig=0, i = 0,count=0;
	while (d[i] != '\0')
	{
		if (d[i] != '/')
		{
			dig = dig * 10 + int(d[i]-'0');
		}
		else
		{
			if (count == 0)
				*dd = dig;
			else if (count == 1)
				*mon = dig;
			count++;
			dig = 0;
		}
		i++;
	}
	*y = dig;
	printf("\n%d %d %d\n", *dd, *mon, *y);
}
void checkDate(int d, int m, int yr)
{
	int flag1 = 0;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		flag1 = 1;
	if (m == 2)
		flag1 = 2;
	convertDate(d, flag1, yr);
}

void convertMonth(int mon)
{
	switch (mon)
	{
	case 1: 		printf("january of ");
		break;
	case 2: 		printf("february of ");
		break;
	case 3: 		printf("march of ");
		break;
	case 4: 		printf("april of ");
		break;
	case 5: 		printf("may of ");
		break;
	case 6: 		printf("june of ");
		break;
	case 7: 		printf("july of ");
		break;
	case 8: 		printf("august of ");
		break;
	case 9:  		printf("september of ");
		break;
	case 10:		printf("october of ");
		break;
	case 11:		printf("november of ");
		break;
	case 12:		printf("december of ");
		break;
	default: 		printf("invalid input \n");
	}
}
void convertDate(int d, int flg, int yr)
{
	int flag = 0;
	switch (flg)
	{
	case 1:
		if (d <= 31)
			flag = 1;
		break;
	case 2:
		if ((yr % 400 == 0) || ((yr % 4 == 0) && (yr % 100 != 0)))//leap year
		{
			if (d <= 29)
				flag = 1;
			break;
		}
		else
			if (d<29)
				flag = 1;
		break;
	case 0:
		if (d <= 30)
			flag = 1;
		break;
	}
	if (flag == 0)
	{
		printf("invalid input\n");
		return;
	}
	else
	{
		format(d);
	}
}
void format(int d)
{
	int d1, d2;
	d1 = d % 10;
	d2 = d / 10;

	if (d!= d1)
	{
		if (d > 10 && d<=19)
		{
			printTensDigit(d);
			printf("th ");
		}
		else if (d == 20)
			printf("twentieth ");
		else if (d == 30)
			printf("thirtieth ");
		else
		{ 
			if (d2 == 2)
				printf("twenty ");
			else if (d2 == 3)
				printf("thirty ");		
			
				printOnesDigit(d1);
		}
	}
	else
		printOnesDigit(d1);

}

void convertYear(int yr)
{
	int d1, d2, d3, d4;
	d1 = yr / 100;
	d2 = yr % 100;
	if (d1<10)
	{
		printOnesDigit1(d1);
		printf("hundred ");
	}
	else if (d1>10 && d1<20)
		printTensDigit(d1);
	else
	{
		if (d1 % 10 == 0)
		{
			printOnesDigit1(d1 / 10);
			printf(" thousand ");
		}
		else
		{
			printDigit((d1 / 10)*10);
			printOnesDigit1(d1 % 10);
		}
	}
	if (d2<10)
		printOnesDigit1(d2);
	else if (d2>10 && d2<20)
		printTensDigit(d2);
	else
	{
		d3 = d2 / 10;
		printDigit(d3 * 10);
		d4 = d2 % 10;
		printOnesDigit1(d4);
	}
}
void printDigit(int d)
{
	switch (d)
	{
		case 10:	printf("ten ");
			break;
		case 20:	printf("twenty ");
			break;
		case 30:	printf("thirty ");
			break;
		case 40:	printf("fourty ");
			break;
		case 50:	printf("fifty ");
			break;
		case 60:	printf("sixty ");
			break;
		case 70:	printf("seventy ");
			break;
		case 80:	printf("eighty ");
			break;
		case 90:	printf("ninty ");
			break;
	}
}
void printTensDigit(int d)
{
	switch (d)
	{
	case 11: 		printf(" eleven");
		break;
	case 12: 		printf(" twevele");
		break;
	case 13: 		printf(" thirteen");
		break;
	case 14: 		printf(" fourteen");
		break;
	case 15: 		printf(" fifteen");
		break;
	case 16: 		printf(" sixteen");
		break;
	case 17: 		printf(" seventeen");
		break;
	case 18: 		printf(" eighteen");
		break;
	case 19: 		printf(" nineteen");
		break;
	}
}

void printOnesDigit(int d)
{
	switch (d)
	{
	case 1: 		printf("first ");
		break;
	case 2: 		printf("second ");
		break;
	case 3: 		printf("third ");
		break;
	case 4: 		printf("fouth ");
		break;
	case 5: 		printf("fifth ");
		break;
	case 6: 		printf("sixth ");
		break;
	case 7: 		printf("seventh ");
		break;
	case 8: 		printf("eighth ");
		break;
	case 9: 		printf("nineth ");
		break;
	}
}
void printOnesDigit1(int d)
{
	switch (d)
	{
	case 1: 		printf("one ");
		break;
	case 2: 		printf("two ");
		break;
	case 3: 		printf("three ");
		break;
	case 4: 		printf("four ");
		break;
	case 5: 		printf("five ");
		break;
	case 6: 		printf("six ");
		break;
	case 7: 		printf("seven ");
		break;
	case 8: 		printf("eight ");
		break;
	case 9: 		printf("nine ");
		break;
	}
}
