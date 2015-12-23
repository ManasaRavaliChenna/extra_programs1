/* 8.Given a linked list which is in pattern like combination of ascending and descending. Sort it.(First all ascending numbers occur ,next all descending nums )
Note : min of descending part is greater than max of ascending 
Ex: Input 1->2->7->20->15->10
Output 1->2->7->10->15->20 */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
void read(int, struct node*);
void insertLast(int, struct node*);
void display(struct node*);
void sortingLLWithEleInAsc_Desc(struct node* h);
void swap(int *, int*);
int main()
{
	struct node* h = (struct node*)malloc(sizeof(struct node));
	int n;
	printf("enter no. of elements");
	scanf_s("%d", &n);
	printf("enter %d elements : ", n);
	read(n, h); //using insert last algorithm
	sortingLLWithEleInAsc_Desc(h->link);
	_getch();
}
void sortingLLWithEleInAsc_Desc(struct node* h)
{
	if (h->link == NULL || h == NULL)
		printf("Linked list is already in ascending order");
	else
	{
		struct node *p = h, *q = h, *prev = NULL, *prev1 = NULL, *temp;
		while ((q->link)&&(q->data < q->link->data))
			q = q->link;
		printf("%d\n", q->data);
		do
		{
			temp = q;
			while (temp->link)
			{				
				prev1 = temp;
				temp = temp->link;
			}
			prev1->link = NULL;
			display(h);
			while (p&&(p->data < temp->data))
			{
				prev = p;
				p = p->link;
			}
			if (prev==NULL)
			{
				temp->link = h;
				h = temp;
				p = h;
				display(h);
			}
			else
			{
				temp->link = p;
				prev->link = temp;
				prev = p;
				p=temp;
			}
		}
		while (temp->data != q->data);
	}
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
	printf("\n");
}