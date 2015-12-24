#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
void insertLast(int,struct node*h); //for inserting new node in last position
void mergeTableAndFindRthMin(int n1,int n2,int r); //creating lists for n1 and n2 tables 
void swap(int*, int*);//swapping values so that n1 and n2 will be ascending
void mergeLLWithoutUsingExtraList(struct node *h1, struct node *h2, int r);//merging tables
void display(struct node * ll);
int main()
{
	int n, n1, r;
	printf("Enter value of num 1: ");
	scanf_s("%d", &n1);
	printf("Enter value of num 2: ");
	scanf_s("%d", &n);
	printf("Enter value of r: ");
	scanf_s("%d", &r);
	mergeTableAndFindRthMin(n1, n, r);
	_getch();
}
//swapping values so that n1 and n2 will be ascending
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
//creating lists for n1 and n2 tables and merging them
void mergeTableAndFindRthMin(int n1, int n2, int r)
{
	struct node *head1 = (struct node*)malloc(sizeof(struct node));
	head1->link = NULL;
	struct node *head2 = (struct node*)malloc(sizeof(struct node));
	head2->link = NULL;
	if (n1 == NULL&&n2 == NULL)
		printf("lists are empty");
	else if (n1 == NULL)
		printf("rth min element is %d", n2*r);
	else if (n2 == NULL || n1 == n2)
		printf("rth min elemets is %d", n1*r);
	else
	{
		if (n1 > n2)
			swap(&n1, &n2);
		for (int i = 1; i <= r; i++)
			insertLast(n1*i, head1);
		for (int i = 1; n2*i < n1*r; i++)
			insertLast(n2*i, head2);
		mergeLLWithoutUsingExtraList(head1, head2,r);
	}
}
void mergeLLWithoutUsingExtraList(struct node *h1, struct node *h2, int r)
{
	int c = 0;
	struct node *n1 = h1->link, *n2 = h2->link;
	for (int i = 0; (n1->link&&n2); n1 = n1->link)
	{
		if (n1->link->data > n2->data)
		{
			if (n1->data != n2->data)
			{
				struct node *p = (struct node*)malloc(sizeof(struct node));
				p->data = n2->data;
				p->link = n1->link;
				n1->link = p;
				i++;
			}
			n2 = n2->link;
		}
		if (i == r)
		{
			printf("%d", n1->data);
			break;
		}
		n1 = n1->link;
		i++;
		if (i == r)
		{
			printf("%d", n1->data);
			break;
		}
	}
}
void display(struct node * ll)
{
	struct node *t = ll;
	while (t)
	{
		printf("%d ", t->data);
		t = t->link;
	}
	printf("\n");
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