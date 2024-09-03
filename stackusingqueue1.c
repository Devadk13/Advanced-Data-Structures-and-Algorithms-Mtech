#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q)
{
    return (q->front == -1);
}

void enqueue(Queue* q, int value)
{
    if(q->rear == MAX-1)
    {
        printf("Queue overflow\n");
        return;
    }
    if(isEmpty(q))
    {
        q->rear = 0;
        q->front = 0;
    }
    else
    {
        q->rear++;
    }
    q->items[q->rear] = value;
}

int dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return value;
}

int front(Queue* q)
{
    if(!isEmpty(q))
    {
        return q->items[q->front];
    }
    return -1;
}

typedef struct{
    Queue q1;
    Queue q2;
} SUQ;

void initStack(SUQ* s)
{
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(SUQ* s, int x)
{
    enqueue(&s->q2, x);
    while(!isEmpty(&s->q1))
    {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(SUQ* s)
{
    if(isEmpty(&s->q1))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

int top(SUQ* s)
{
    return front(&s->q1);
}

bool empty(SUQ* s)
{
    return isEmpty(&s->q1);
}

void display(SUQ* s)
{
    if(isEmpty(&s->q1))
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are: ");
    for(int i = s->q1.front; i <= s->q1.rear; i++)
    {
        printf("%d ", s->q1.items[i]);
    }
    printf("\n");
}

int main()
{
    SUQ s;
    initStack(&s);
    int d;
    int choice;
    printf("Implementation of stack using queue : Making Push costly\n");

    do
    {
        printf("Enter 1 for push, 2 for pop, 3 for peek, 4 for display, 5 to exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to push\n");
                scanf("%d", &d);
                push(&s, d);
                break;
            case 2:
                printf("Popped element is: %d\n", pop(&s));
                break;
            case 3:
                printf("Top element is: %d\n", top(&s));
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}
