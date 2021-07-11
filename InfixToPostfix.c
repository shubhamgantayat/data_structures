#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
typedef struct {
    char ar[MAX];
    int top;
}stack;
void push(stack*,char);
char pop(stack*);
bool isFull(stack);
bool isEmpty(stack);
int precedence(char);
int main() {
    char postfix[MAX],infix[MAX],ch,element;
    stack s;
    int i,len,pos=0;
    s.top = -1;
    printf("\nEnter infix exp : ");
    scanf("%[^\n]",infix);
    push(&s,'(');
    strcat(infix,")");
    for(i = 0;infix[i]!=0;i++) {
        ch = infix[i];
        if(isalpha(ch)) {
            postfix[pos] = ch;
            pos++;
        }
        else if(ch == ')') {
            while(s.ar[s.top] != '(') {
                element = pop(&s);
                postfix[pos] = element;
                pos++;
            }
            element = pop(&s);
        }
        else if(ch == '(')
            push(&s,ch);
        else {
            while(precedence(ch) <= precedence(s.ar[s.top])) {
                element = pop(&s);
                postfix[pos] = element;
                pos++;
            }
            push(&s,ch);
        }
    }
    postfix[pos]='\0';
    printf("\nPostfix expression : %s",postfix);
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

void push(stack *s,char element) {
    if(isFull(*s))
        printf("\nStack Overflow");
    else {
        s->top ++;
        s->ar[s->top] = element;
    }
}

char pop(stack *s) {
    char element;
    if(isEmpty(*s)) {
        printf("\nStack underflow");
        return '@';
    }
    else {
        element = s->ar[s->top];
        s->top --;
        return element;
    }
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        case '(':
            return -1;
    }
}

