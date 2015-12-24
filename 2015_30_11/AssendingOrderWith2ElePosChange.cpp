/*7.Sorted a linked list which is in ascending order but two numbers are changed, i mean not in the usual order they need to be
Ex : 1->2->3->15->10->4->20; O / p:1 - 2 - 3 - 4 - 10 - 15 - 20*/
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
void correctPositions(struct node*);
void swap(int *,int*);
int main()
{
	struct node* h = (struct node*)malloc(sizeof(struct node));
	int n;
	printf("enter no. of elements");
	scanf_s("%d", &n);
	printf("enter %d elements : ", n);
	read(n, h);
	correctPositions(h->link);
	_getch();
}
void correctPositions(struct node* h)
{
	//for finding position of first element in wrong position
	struct node *pres = h;  
	struct node *prev=NULL;
	while (pres->link)
	{
		if (pres->data > pres->link->data)
			break;
		prev = pres;
		pres = pres->link;
	}
	// All Elements are in crt order
	if (pres->link == NULL)
	{
		printf("All the elements are in ascending order");
		return;
	}
	//for finding position of second element in wrong position
	//if last two elements are in wrong order
	if (!pres->link->link)
	{ 
		swap(&pres->data, &pres->link->data);
		display(h);
	}
	else
	{
		struct node *pres2 = pres->link;
		struct node *next = pres->link->link;
		while (next)
		{
			if (pres2->data > next->data)
				break;
			pres2 = next;
			next = next->link;
		}
		//if we didnt get any pos in the above loop it means that the required elements are adj to each other
		if (next == NULL)
		{
			swap(&pres->data, &pres->link->data);
			display(h);
		}
		//otherwise
		else
		{
			swap(&pres->data, &next->data);
			display(h);
		}
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
}