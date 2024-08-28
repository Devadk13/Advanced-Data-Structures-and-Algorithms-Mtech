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
    while(!isEmpty(&q->stack1))
    {
        push(&q->stack2,pop(&q->stack1));
    }

    push(&q->stack1,data);

    while(!isEmpty(&q->stack2))
    {
        push(&q->stack1,pop(&q->stack2));
    }
}



int dequeue(Queue* q)
{
    if(isEmpty(&q->stack1))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(&q->stack1);
}

void display(Queue* q)
{
    for(int i=0;i<=q->stack1.top;i++)
    {
        printf("%d ",q->stack1.items[i]);
    }

}

int main()
{
    Queue q;
    initQ(&q);
    enqueue(&q, 15);
    enqueue(&q, 27);
    enqueue(&q, 31);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));


    enqueue(&q, 40);
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}







