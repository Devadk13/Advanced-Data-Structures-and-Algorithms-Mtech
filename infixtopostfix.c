#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct
{

    int top;
    char items[MAX];
}Stack;

void initStack(Stack* s)
{

    s->top=-1;
}

int isEmpty(Stack* s)
{

    return s->top==-1;
}

void push(Stack* s,char value)
{
    if(s->top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)]=value;
}

char pop(Stack* s)
{
    if(isEmpty(s))
    {
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack* s)
{
    if(isEmpty(s))
    {
        return '\0';
    }
    return s->items[s->top];
}

int isOperand(char ch)
{
    return isdigit(ch);
}


int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
          return 1;

        case '*':
        case '/':
         return 2;
        default:
            return 0;

    }
}


void infixToPostfix(char* infix,char* postfix)
{
    Stack stack;
    initStack(&stack);
    int k=0;

    for(int i=0;infix[i]!='\0';i++)
    {


        char ch=infix[i];

        if(isOperand(ch))
        {

            postfix[k++]=ch;
        }
        else if(ch=='(')
        {
            push(&stack,ch);
        }

        else if(ch==')')
        {
            while(!isEmpty(&stack) && peek(&stack)!='(')
            {
                postfix[k++]=pop(&stack);
            }
            pop(&stack);
        }

        else
        {

            while(!isEmpty(&stack) && precedence(ch)<=precedence(peek(&stack)))
            {
                postfix[k++]=pop(&stack);
            }
            push(&stack,ch);
        }
    }

    while(!isEmpty(&stack))
    {
        postfix[k++]=pop(&stack);
    }

    postfix[k]='\0';


}

int main()
{
    char infix[MAX],postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s",infix);

    infixToPostfix(infix,postfix);

    printf("Postfix expression is : %s\n",postfix);

    return 0;
}

