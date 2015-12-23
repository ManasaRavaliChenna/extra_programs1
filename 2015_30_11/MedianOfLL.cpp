//Find median of a given linked list (Sorted Linked List)

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
void insertLast(int, struct node*h);  //inserting elements into linked list
void findMedian(struct node *head);  //for finding median of element in linkedlist
void read(int, struct node*);		 //for reading elements
int main()
{
	int n, ele;
	struct node *head = (struct node*)malloc(sizeof(struct node));
	printf("enter no. of elemets : ");
	scanf_s("%d", &n);
	read(n, head);
	findMedian(head);
	_getch();
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
void findMedian(struct node *head)
{
	struct node *p, *q;
	p = head->link;
	if (p == NULL)                   //when there are no elements in linked list
		printf("size is 0 no median");
	else if (p->link == NULL)        //when there is a single element in linkedlist
		printf("median is %f", float(p->data));
	else
	{
		q = head->link;
		while (q->link->link)
		{
			p = p->link;
			q = q->link;
			q = q->link;
			if (!q || !q->link)
				break;
		}
		if (!q->link)				//when there are odd no. of elemets
			printf("median is %f", float(p->data));
		else						//whwn there are even no. of elements
			printf("median is %f", (float(p->data) + float(p->link->data)) / 2);
	}
}