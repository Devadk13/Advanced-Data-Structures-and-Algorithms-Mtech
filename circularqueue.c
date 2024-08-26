#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct CircularQueue
{
    int arr[SIZE];
    int front,rear;
};

void initialize(struct CircularQueue *q)
{

    q->front=-1;
    q->rear=-1;
}

int isFull(struct CircularQueue *q)
{
    return (q->front ==0 && q->rear ==SIZE-1)||(q->rear==(q->front-1)%(SIZE));
}

int isEmpty(struct CircularQueue *q)
{
    return q->front==-1;
}

void enqueue(struct CircularQueue *q,int value)
{

    if(isFull(q))
    {
        printf("Queue is Full\n");
        return;

    }
    else if(q->front==-1)
    {
        q->front=q->rear=0;
    }
    else if(q->rear==SIZE-1 && q->front!=0)
    {
        q->rear=0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear]=value;
    printf("Inserted: %d\n",value);

}

void dequeue(struct CircularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    int data=q->arr[q->front];
    q->arr[q->front]=-1;

    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else if(q->front==SIZE-1)
    {
        q->front=0;
    }
    else{
        q->front++;
    }

    printf("Deleted : %d\n",data);

    return;
}



void display(struct CircularQueue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    } else {
        for (int i = q->front; i < SIZE; i++)
            printf("%d ", q->arr[i]);
        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    }
    printf("\n");
}




int main()
{
    struct CircularQueue q;
    initialize(&q);
    int choice=0;;

    printf("Circular Queue\n");
int num;
    do{

        printf("Enter 1 for enqueue\n2 for dequeue \n3 for displaying \n4 for exit\n");

    scanf("%d",&choice);

    if (choice==1)
    {
        printf("Enter the number to enqueue: ");
        scanf("%d",&num);
        enqueue(&q,num);

    }
    else if(choice==2)
    {
        dequeue(&q);
    }

    else if(choice==3)
    {

    display(&q);
    }

    }while(choice!=4);






    return 0;
}
