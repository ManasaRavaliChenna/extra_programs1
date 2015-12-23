#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
void insertLast(int, struct node*h);
void read(struct node*);
void reverseUsingExtraList(struct node *head1, struct node *head2);
void display(struct node * ll);
int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *rev = (struct node*)malloc(sizeof(struct node));
	rev->link = NULL;
	read(head);
	reverseUsingExtraList(head->link,rev);
	display(rev->link);
	_getch();
}
void reverseUsingExtraList(struct node *head, struct node *rev)
{
	if (head == NULL)
		return;
	else
	{
		struct node*q = head;
		head = head->link;
		q->link = rev->link;
		rev->link = q;
		reverseUsingExtraList(head, rev);
	}
}
void reverseWithOutUsingExtraList(struct node *head)
{
	if (head == NULL)
		return;
	else
	{
		struct node *t = head,*p=(struct node*)malloc(sizeof(struct node));
		while (t->link)
			t = t->link;
		printf("%d ", t->data
		p = t->link;
		printf("%d ", p->data);
		t->link = NULL;
		p->link = head;
		head = p;
		reverseWithOutUsingExtraList(head);
	}
}
void read(struct node* h)
{
	int ele, n;
	printf("enter no. of elements : ");
	scanf_s("%d", &n);
	h->link = NULL;
	printf("enter %d elemets : ", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &ele);
		insertLast(ele, h);
	}
	display(h->link);
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