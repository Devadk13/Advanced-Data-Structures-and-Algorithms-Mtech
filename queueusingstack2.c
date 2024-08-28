#include <stdio.h>
#include <stdlib.h>


#define MAX 100

typedef struct{
int top;
int items[100];

}Stack;



void initStack(Stack* s)
{
    s->top=-1;
    return;

}

int isEmpty(Stack* s)
{
    return s->top==-1;

}

int isFull(Stack* s)
{
    return s->top==MAX-1;
}

void push(Stack* s,int data)
{
    if(isFull(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)]=data;

}

int pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}


typedef struct
{

    Stack stack1;
    Stack stack2;
}Queue;


void initQ(Queue* q)
{
    initStack(&q->stack1);
    initStack(&q->stack2);
}

void enqueue(Queue* q,int data)
{
    push(&q->stack1,data);
}



int dequeue(Queue* q)
{
    if(isEmpty(&q->stack2))
    {

        if(isEmpty(&q->stack1))
        {
            printf("Queue is empty\n");
            return -1;
        }
        while(!isEmpty(&q->stack1))
        {
            push(&q->stack2,pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}

void display(Queue* q)
{
    for(int i=q->stack2.top;i>=0;i--)
    {
        printf("%d ",q->stack2.items[i]);
    }

    for(int j=0;j<=q->stack1.top;j++)
    {
        printf("%d ",q->stack1.items[j]);
    }
    printf("\n");

}

int main()
{
    Queue q;
    initQ(&q);
    enqueue(&q,12);
    enqueue(&q, 27);
    enqueue(&q, 31);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);


    enqueue(&q, 40);
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}







