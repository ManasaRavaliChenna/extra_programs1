/*Write a program to add two linked list (Each node is represented by a digit ) (Note: Unequal Lengths can also be given )
Ex: Input 1->2->3->4 and 1->2->3->4
Output 2->4->6->8*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node  
{
	int data;
	struct node *link;
};
void read(int, struct node*);//reading values from input
void insertLast(int, struct node*);//lasting number at the last node
void display(struct node*);//displaying linkedlists
void add_twoll(struct node*,struct node*);//addind 2 linked list
void swap(struct node *, struct node *);
int main()
{
	struct node* h1 = (struct node*)malloc(sizeof(struct node));
	struct node* h2 = (struct node*)malloc(sizeof(struct node));
	int n1,n2;
	printf("enter no. of elements");
	scanf_s("%d", &n1);
	printf("enter %d elements : ", n1);
	read(n1, h1);
	printf("enter no. of elements");
	scanf_s("%d", &n2);
	printf("enter %d elements : ", n2);
	read(n2, h2);
	add_twoll(h1->link,h2->link);
	_getch();
}
void add_twoll(struct node* h1,struct node *h2)
{
	struct node *ll1 = h1, *ll2 = h2, *add_carry_digit = (struct node*)malloc(sizeof(struct node)), *sum = (struct node*)malloc(sizeof(struct node));
	add_carry_digit = NULL;//to point to a location having value less than 9 so that even though we get carry values befor if are not disturbed
	int num_ele1 = 0, num_ele2 = 0;
	//for finding no.of elements in linkedlist 1
	for (int i = 0; ll1; ll1 = ll1->link)
		num_ele1++;
	//for finding no.of elements in linkedlist 2
	for (int i = 0; ll2; ll2 = ll2->link)
		num_ele2++;
	//storing the linked list having more elements in n1
	if (num_ele1 > num_ele2)
	{
		ll1 = h1;
		//0 is stored at the begining so that even a carry at most significant postion can be handled
		struct node *g = (struct node *)malloc(sizeof(struct node));
		g->data = 0;
		g->link = h1;
		sum = g;
		ll2 = h2;
	}
	else
	{
		ll1 = h2;
		sum = h2;
		struct node *g = (struct node *)malloc(sizeof(struct node));
		g->data = 0;
		g->link = h2;
		sum = g;
		ll2 = h1;
	}
	//to point ll1 to a node from which addition can be performed
	for (int i = 0; i < (num_ele1 - num_ele2 ) || i < (num_ele2 - num_ele1 ); i++, ll1 = ll1->link)
	{
		if (ll1->data < 9)
			add_carry_digit = ll1;
	}
	while (ll1&&ll2)
	{
		//sum is less than 9 so cahange pos of caarry digit
		if ((ll1->data + ll2->data )< 9)
		{
			ll1->data = ll1->data + ll2->data;
			add_carry_digit = ll1;
		}
		//increase carry digit value by 1 and make others 0 until u get ll1
		else
		{
			ll1->data = (ll1->data + ll2->data) % 10;
			add_carry_digit->data += 1;
			add_carry_digit = add_carry_digit->link;
			while (add_carry_digit!=ll1)
			{
				printf("%d ", add_carry_digit->data);
				add_carry_digit->data = 0;
				add_carry_digit = add_carry_digit->link;
			}
		}
		ll1 = ll1->link;
		ll2 = ll2->link;
	}
	display(sum);
}
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void read(int n, struct node* h)
{
	int ele;
	h->link = NULL;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &ele);
		insertLast(ele, h);
	}
}
void insertLast(int ele, struct node* h)
{
	struct node* p = (struct node*)malloc(sizeof(struct node));
	p->data = ele;
	p->link = NULL;
	if (h->link == NULL)
		h->link = p;
	else
	{
		struct node* t = h->link;
		while (t->link)
			t = t->link;
		t->link = p;
	}
}
void display(struct node* h)
{
	struct node *t = h;
	while (t)
	{
		printf("%d ", t->data);
		t = t->link;
	}
}