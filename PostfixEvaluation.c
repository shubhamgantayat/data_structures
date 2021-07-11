#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
typedef struct {
    int ar[MAX];
    int top;
}stack;
void push(stack*,int);
int pop(stack*);
bool isFull(stack);
bool isEmpty(stack);
int main() {
    char exp[MAX];
    int x,i,y;
    stack s;
    s.top = -1;
    printf("\nEnter the exp : ");
    scanf("%[^\n]",exp);
    for(i = 0;exp[i]!=0;i++) {
        if(isalpha(exp[i])) {
            printf("\nEnter the value of %c : ",exp[i]);
            scanf("%d",&x);
            push(&s,x);
        }
        else {
            y = pop(&s);
            x = pop(&s);
            switch(exp[i]) {
                case '+':
                    push(&s,x+y);
                    break;
                case '-':
                    push(&s,x-y);
                    break;
                case '*':
                    push(&s,x*y);
                    break;
                case '/':
                    push(&s,x/y);
                    break;
                case '%':
                    push(&s,x%y);
                    break;
                case '^':
                    push(&s,pow(x,y));
                    break;
            }
        }
    }
    printf("\nValue of exp : %d",s.ar[0]);
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
        return element;
    }
}
