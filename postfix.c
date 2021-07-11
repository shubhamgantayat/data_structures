#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
typedef struct
{
	int ar[MAX];
	int top;
}stack;
void push(stack*,int);
int pop(stack*);
int main()
{
	system("clear");
	stack s;
	s.top=-1;
        char str[MAX];
	int i,x,y,z;
	printf("\nEnter the postfix exp: ");
	scanf(" %[^\n]",str);
	for(i=0;str[i]!=0;i++)
	{
		if(isalpha(str[i]))
		{
			printf("\nEnter the value of %c: ",str[i]);
			scanf("%d",&x);
			push(&s,x);
		}
		else
		{
			y=pop(&s);
			z=pop(&s);
			switch(str[i])
			{
				case '+':push(&s,z+y);
					 break;
				case '-':push(&s,z-y);
					 break;
				case '*':push(&s,z*y);
					 break;
				case '/':push(&s,z/y);
					 break;
				case '%':push(&s,z%y);
					 break;
				case '^':push(&s,pow(z,y));
					 break;
			}
		}
	}
	printf("\nValue of postfix exp: %d\n",s.ar[0]);
	return 0;
}
void push(stack *s,int x)
{
	if(s->top==MAX-1)
		printf("\nStack overflow\n");
	else
	{
		s->top++;
		s->ar[s->top]=x;
	}
}
int pop(stack *s)
{
	int x;
	if(s->top==-1)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		x=s->ar[s->top];
		s->top--;
		return x;
	}
}
