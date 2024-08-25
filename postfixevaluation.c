#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    int top;
    char items[MAX];
}Stack;


typedef struct
{

    int top;
    int items[MAX];
}IntStack;

void initStack(Stack* s)
{
    s->top=-1;

}

void initIntStack(IntStack* s)
{

    s->top=-1;
}

int isEmpty(Stack* s)
{
    return s->top==-1;

}

int isEmptyIntStack(IntStack* s)
{
    return s->top==-1;


}



void push(Stack* s,char value)
{
    if(s->top==MAX-1)
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)]=value;

}
void pushInt(IntStack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

int popInt(IntStack* s) {
    if (isEmptyIntStack(s)) {
        printf("Stack Underflow\n");
        return 0;
    }
    return s->items[(s->top)--];
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

int isOperand(char ch) {
    return isdigit(ch);
}

int precedence(char op) {
    switch (op) {
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

int validateExpression(char* infix) {
    int balance = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (!isdigit(ch) && !strchr("+-*/()", ch)) {
            printf("Invalid character in expression: %c\n", ch);
            return 0;
        }
        if (ch == '(') balance++;
        if (ch == ')') balance--;
        if (balance < 0) {
            printf("Mismatched parentheses\n");
            return 0;
        }
    }
    if (balance != 0) {
        printf("Mismatched parentheses\n");
        return 0;
    }
    return 1;
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
    }while(!isEmpty(&stack))
{

    postfix[k++]=pop(&stack);
}


    postfix[k]='\0';
}


int evaluatePostfix(char* postfix)
{

    IntStack stack;
    initIntStack(&stack);

    for(int i=0;postfix[i]!='\0';i++)
    {
        char ch=postfix[i];


    if(isOperand(ch))
    {

        pushInt(&stack,ch-'0');
    }
    else{
        if(stack.top<1)
        {
            printf("Error:Insufficient operands");
            return 0;
        }

        int val2=popInt(&stack);
        int val1=popInt(&stack);

        if(ch=='/' && val2==0)
        {
            printf("Division by zero error");
            return 0;
        }

        switch (ch)
        {
            case '+':pushInt(&stack,val1+val2);break;
            case '-':pushInt(&stack,val1-val2);break;
            case '*':pushInt(&stack,val1*val2);break;
            case '/':pushInt(&stack,val1/val2);break;
            default:
                printf("Invalid operation");
                return 0;
        }
    }
}

if(stack.top!=0)
{
    printf("Error:Invalid");
    return 0;

}

return popInt(&stack);

}


int main()
{

    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix,MAX,stdin);

    size_t len =strlen(infix);

    if(len>0 && infix[len-1]=='\n')
    {
        infix[len-1]='\0';
    }
    if (!validateExpression(infix)) {
        getchar();  // Wait for user input before exiting
        return 1;
    }

    infixToPostfix(infix, postfix);
    int result = evaluatePostfix(postfix);

    if (result != 0 || isdigit(postfix[0])) {
        printf("Computed value of the expression: %d\n", result);
    }

    getchar();  // Wait for user input before exiting
    return 0;


}





