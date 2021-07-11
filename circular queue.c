#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct
{
	int front,rear;
	int ar[MAX];
}queue;
void Qinsert(queue*,int);
int Qdelete(queue*);
void Qdisplay(queue*);
int main()
{
	system("clear");
	queue q;
	q.front=-1;
	q.rear=-1;
	int ch,x;
	while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the no. to be inserted: ");
			       scanf("%d",&x);
			       Qinsert(&q,x);
			       break;
			case 2:x=Qdelete(&q);
			       printf("\nThe deleted element is: %d\n",x);
			       break;

			case 3:Qdisplay(&q);
			       break;
			case 4:exit(0);
			default:printf("\nInvalid choice: \n");
		}
	}
	return 0;
}
void Qinsert(queue *q,int x)
{
	if(q->front==(q->rear+1)%MAX)
		printf("\nQueue is full\n");
	else if(q->front==-1)
	{
		q->front=0;
		q->rear=0;
		q->ar[q->rear]=x;
	}
	else
	{
		q->rear=(q->rear+1)%MAX;
		q->ar[q->rear]=x;
	}
}
int Qdelete(queue *q)
{
	int x;
	if(q->front==-1)
	{
		printf("\nQueue is empty\n");
		return;
	}
	else if(q->front==q->rear)
	{
		x=q->ar[q->front];
		q->front=-1;
		q->rear=-1;
		return x;
	}
	else
	{
		x=q->ar[q->front];
		q->front=(q->front+1)%MAX;
		return x;
	}
}
void Qdisplay(queue *q)
{
	int i;
	if(q->front==-1)
		printf("\nQueue is empty\n");
	else
	{
		printf("\nQueue\n");
		for(i=q->front;i!=q->rear;i=((i+1)%MAX))
			printf("%d\t",q->ar[i]);
		printf("%d\n",q->ar[i]);
	}
}
