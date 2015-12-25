#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* link;
};
void display(struct node*);//display elemens in circular list
void addEleinCLL(struct node* h, int x);//add new element in first position
void createCircularList(struct node* h);//create circular list
int main()
{
	int x;
	struct node*head=(struct node*)malloc(sizeof(struct node));
	head->link = head;
	printf("enter 7 elements in circular linked list : ");
	createCircularList(head);
	display(head->link);
	printf("Enter value to be added in the list : ");
	scanf_s("%d", &x);
	addEleinCLL(head, x);
	display(head->link);
	_getch();
}
void createCircularList(struct node *h)
{
	int ele;
	for (int i = 0; i < 7; i++)
	{
		scanf_s("%d", &ele);
		addEleinCLL(h, ele);
	}
}
void addEleinCLL(struct node* h, int x)
{
	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	t->link = h->link;
	h->link = t;
}
void display(struct node* h)
{
	struct node *temp=h;
	printf("before ");
	while (temp->link != h)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("after ");
}