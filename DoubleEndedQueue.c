#include <stdio.h>
#include <stdlib.h>
#define N 7
typedef struct
{
    int data[7];      //List containing data
    int front;        //Must be initialized to minus one at start of program
    int rear;         
}QUEUE;

int isFull(QUEUE *q)
{
    if (((q->rear+1)%N)==q->front) //Check if QUEUE is Full, same as circular Queue
    {
        return(1);
    }                
    return(0);
}
int isEmpty(QUEUE *q)
{
    if (q->front==-1 && q->rear==-1) //if front and rear -1 then empty
    {
        return(1);
    }
    return(0);
}
void insertfront(QUEUE *q,int x)
{
    if (isFull(q))         //Check if Queue is full
        printf("Overflow Error ! ");
    else if (isEmpty(q))   //If empty set both to 0
    {
        q->front=0;
        q->rear++;
        q->data[q->front]=x;
    }
    else if (q->front==0) //If Front is Zero, must circularly update the last element
    {
        q->front=N-1;          
        q->data[q->front]=x;
    }
    else
    {
        q->front=q->front-1; // now decrement front and update value
        q->data[q->front]=x;
    }
}
void insertrear(QUEUE *q,int x)
{
    if (isFull(q))
        printf("Overflow Error ! ");
    else if (isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->data[q->rear]=x;
    }
    else
    {
        q->rear=(q->rear+1)%N; // add to rear and add element
        q->data[q->rear]=x;
    }
}
void deletefront(QUEUE *q)
{
    if (isEmpty(q))
        printf("Underflow Error ! ");
    else if (q->front == q->rear)
    {
        printf("Popped : %d",(q->data[(q->front)]));
        q->front=q->rear=-1;
    }
    else
    {
        printf("Popped : %d",(q->data[(q->front)])); //return popped element and increment front
        q->front=(q->front+1)%N;
    }
}
void deleterear(QUEUE *q)
{
    if (isEmpty(q))
        printf("Underflow Error ! ");
    else if (q->front == q->rear)
    {
        printf("Popped : %d",(q->data[(q->rear)]));
        q->front=q->rear=-1;
    }
    else if (q->rear==0) //must circularly update to last element
    {
        printf("Popped : %d",(q->data[(q->rear)]));
        q->rear=N-1;
    }
    else
    {
        printf("Popped : %d",(q->data[(q->rear)])); //return popped element and decrement rear
        q->rear=q->rear-1;
    }
}
void display(QUEUE *q)
{
    int i=q->front;
    while(i!=q->rear) //display from front to rear
    {
        printf("%d ",q->data[i]);
        i=(i+1)%N;
    }
    printf("%d ",q->data[i]);
}   
int main()
{
    QUEUE *q=(QUEUE*)malloc (sizeof(QUEUE)); //memory allocation
    int ch=0;
    q->front=q->rear=-1; //initialisation important
    do
    {
        printf("Enter choice : 1)Insert Front 2)Insert Rear 3)Delete Rear 4)Delete Front 5)Display : ");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter element : ");
            int x;
            scanf("%d",&x);
            insertfront(q,x);
        }
        if (ch==2)
        {
            printf("Enter element : ");
            int x;
            scanf("%d",&x);
            insertrear(q,x);
        }
        else if (ch==3)
        {
            deleterear(q);
        }
        else if (ch==4)
        {
            deletefront(q);
        }
        else if (ch==5)
        {
            display(q);
        }
        else
        {
            break;
        }
    }while(ch<6);
}