/*2.Merge two linked list which are in sorted order*/

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
void insertLast(int,struct node*h);//crating linkedlist
void read(struct node*);//reading values from input
void mergeLLWithoutUsingExtraList(struct node *h1, struct node *h2);//merging two linkedlists and storing result in first list
void display(struct node * ll);//displaying linked list
int main()
{
	struct node *head1 = (struct node*)malloc(sizeof(struct node));
	struct node *head2 = (struct node*)malloc(sizeof(struct node));
	read(head1);
	read(head2);
	mergeLLWithoutUsingExtraList(head1, head2);
	_getch();
}
//merging two linkedlists and storing result in first list
void mergeLLWithoutUsingExtraList(struct node *h1, struct node *h2)
{
	if (h1->link == NULL&&h2->link == NULL)
		printf("lists are empty");
	else if (h1->link == NULL)
		display(h2->link);
	else if (h2->link == NULL)
		display(h1->link);
	else
	{
		printf("pppp");
		struct node *n1 = h1->link, *n2 = h2->link;
		if (n1->data > n2->data)
		{
			struct node *p = (struct node*)malloc(sizeof(struct node));
			p->data = n2->data;
			p->link = n1->link;
			h1->link = p;
			n2 = n2->link;
		}
		while (n1->link&&n2)
		{
			//manipulating first list when n2 has lesser element than n1
			if (n1->link->data > n2->data)
			{
				if (n1->data != n2->data)
				{
					//adding node to the list 
					struct node *p = (struct node*)malloc(sizeof(struct node));
					p->data = n2->data;
					p->link = n1->link;
					n1->link = p;
				}
				n2 = n2->link;
			}
			n1 = n1->link;
		}
		//when is at last node and still there are nodes that are nodes in n1 that arenot visted 
		if (n2)
			n1->link = n2;
	}
	display(h1->link);
}
//merging two linkedlists and storing result in new list
void mergeLL(struct node *h1, struct node* h2)
{
	if (h1->link == NULL&&h2->link == NULL)
		printf("lists are empty");
	else if (h1->link == NULL)
		display(h2->link);
	else if (h2->link == NULL)
		display(h1->link);
	else
	{
		struct node *n = (struct node *)malloc(sizeof(struct node)), *n3;
		n->data = -1;
		n->link = NULL;
		n3 = n;
		struct node *n1 = h1->link, *n2 = h2->link;
		//storing values in n3 in ascending order checking values in n1 and n2
		while (n1&&n2)
		{
			if (n1->data < n2->data)
			{
				n3->data = n1->data;
				n3->link = (struct node *)malloc(sizeof(struct node));
				n1 = n1->link;
				n3 = n3->link;
			}
			else if (n1->data > n2->data)
			{
				n3->data = n2->data;
				n3->link = (struct node *)malloc(sizeof(struct node));
				n2 = n2->link;
				n3 = n3->link;
			}
			else
			{
				n3->data = n2->data;
				n3->link = (struct node *)malloc(sizeof(struct node));
				n2 = n2->link;
				n1 = n1->link;
				n3 = n3->link;
			}
		}
		//when there are elements in n1 that have not been traversed
		if (n1)
			n3->link = n1;
		//when there are elements in n2 that have not been traversed
		if (n2)
			n3->link = n2;
		n3->link = NULL;
		display(n);
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
void read(struct node* h)
{
	int ele,n;
	printf("enter no. of elements : ");
	scanf_s("%d", &n);
	h->link = NULL;
	printf("enter %d elemets : ", n);
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