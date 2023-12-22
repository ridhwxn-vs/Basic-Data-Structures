#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data[7];      //List containing data
    int front;        //Must be initialized to minus one at start of program
    int rear;         
}QUEUE;
int isFull(QUEUE *q)
{
    if (q->rear==6) //Check if QUEUE is Full
    {
        return(1);
    }                
    return(0);
}
int isEmpty(QUEUE *q)
{
    if (q->front==q->rear) //if front = rear set to -1
    {
        q->front=q->rear=-1;
        return(1);
    }
    return(0);
}
void insert(QUEUE *q,int x)
{
    if (isFull(q))
        printf("Overflow Error ! ");
    else
    {
        if(q->front==-1) //increment initial front from -1 to 0
            q->front++;
        q->rear+=1; // add to rear and add element
        q->data[q->rear]=x;
    }
}
int delete(QUEUE *q)
{
    if (isEmpty(q))
        printf("Underflow Error ! ");
    else
    {
        return(q->data[(q->front)++]); //return popped element and increment front
    }
}
void display(QUEUE *q)
{
    for(int i=q->front;i<=q->rear;i++) //display from front to rear
    {
        printf("%d ",q->data[i]);
    }
}   
int main()
{
    QUEUE *q=(QUEUE*)malloc (sizeof(QUEUE)); //memory allocation
    int ch=0;
    q->front=q->rear=-1; //initialisation important
    do
    {
        printf("Enter choice : 1)Inser 2)Delete 3)Display : ");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter element : ");
            int x;
            scanf("%d",&x);
            insert(q,x);
        }
        else if (ch==2)
        {
            printf("Popped : %d",delete(q));
        }
        else if (ch=3)
        {
            display(q);
        }
        else
        {
            ch=4;
            break;
        }
    }while(ch<4);
}