#include <stdio.h>
#include <stdlib.h>
#define N 7
typedef struct
{
    int front;
    int rear;
    char item[N];
}CQUEUE;
void enqueue(CQUEUE *q,char s)
{
    if ((q->rear+1)%N==q->front) //rear+1=front in circular array, otherwise if rear==N-1
        printf("Queue Full");
    else if(q->rear==-1 && q->front==-1) //if both -1, shift to 0 then update
    {
        q->rear=q->front=0;
        q->item[q->rear]=s;
    }
    else
    {
        q->rear=(q->rear+1)%N; //rear++, but in circular model
        q->item[q->rear]=s;
    }
}
void dequeue(CQUEUE *q)
{
    if(q->rear==-1 && q->front==-1)
        printf("Empty Queue");
    else if(q->rear==q->front) //both are same, meaning only one element in queue, set to -1 and print
    {
        printf("Dequeued %c",q->item[q->front]);
        q->rear=q->front=-1;
    }
    else
    {
        printf("Dequeued %d",q->item[q->front]);
        q->front=(q->front+1)%N; //front++, but in circular model
    }
}
void display(CQUEUE*q)
{
    int i=q->front; //from front
    while (i<=q->rear) //until rear
    {
        printf("%c ",q->item[i]);
        i=(i+1)%N; //update i in circular model
    }
}
int main()
{
    CQUEUE c;
    c.front=c.rear=-1;
    int ch=0;
    char ele;
    do
    {
        printf("Enter what you want to do : 1)Enqueue 2)Dequeue 3)Display");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter element to push : ");
            scanf(" %c",&ele);
            enqueue(&c,ele);
        }
        else if (ch==2)
            dequeue(&c);
        else if (ch==3)
            display(&c);
        else
            ch=99;
    }while (ch<=3);
}