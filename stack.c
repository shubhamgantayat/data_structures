#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
typedef struct {
    int ar[MAX];
    int top;
}stack;
void push(stack*,int);
int pop(stack*);
bool isFull(stack);
bool isEmpty(stack);
void display(stack);

int main() {
    int ch,element;
    stack s;
    s.top = -1;
    system("cls");
    while(1) {
        printf("\n1. PUSH\n2. POP\n3. DISPlAY\n4. EXIT\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("\nEnter the element to be pushed : ");
                scanf("%d",&element);
                push(&s,element);
                break;
            case 2:
                element = pop(&s);
                printf("\nThe element to be deleted : %d",element);
                break;
            case 3:
                display(s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice");
        }
    }
    return 0;
}

bool isFull(stack s) {
    if(s.top == MAX-1)
        return 1;
    else
        return 0;
}

bool isEmpty(stack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}

void push(stack *s,int element) {
    if(isFull(*s))
        printf("\nStack Overflow");
    else {
        s->top ++;
        s->ar[s->top] = element;
        printf("\nElement successfully pushed.");
    }
}

int pop(stack *s) {
    int element;
    if(isEmpty(*s)) {
        printf("\nStack underflow");
        return -999;
    }
    else {
        element = s->ar[s->top];
        s->top --;
        printf("\nElement successfully poped");
        return element;
    }
}

void display(stack s) {
    if(isEmpty(s)) {
        printf("Stack is empty");
    }
    else {
        printf("Stack - \n");
        for(int i = s.top;i>=0;i--)
            printf("%d\n",s.ar[i]);
    }
}
