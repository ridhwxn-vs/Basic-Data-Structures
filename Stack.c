#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int data[7];    //List containing data
    int top;        //Must be initialized to one at start of program
}STACK;
int isFull(STACK *s)
{
    if (s->top==7) //Check if Stack is Full
        return(1);
    return(0);
}
int isEmpty(STACK *s)
{
    if (s->top==-1) //Check if Stack is Empty
        return(1);
    return(0);
}
void push(STACK *s,int x)
{
    if (isFull(s))
        printf("Overflow Error ! ");
    else
    {
        s->top+=1; // increment top and add element
        s->data[s->top]=x;
    }
}
int pop(STACK *s)
{
    if (isEmpty(s))
        printf("Underflow Error ! ");
    else
    {
        return(s->data[(s->top)--]); //return popped element and decrement
    }
}
void display(STACK *s)
{
    for(int i=0;i<=s->top;i++) //display until top only required
    {
        printf("%d ",s->data[i]);
    }
}   
int main()
{
    STACK *s=(STACK*)malloc (sizeof(STACK)); //memory allocation
    int ch=0;
    s->top=-1; //initialisation important
    do
    {
        printf("Enter choice : 1)Push 2)Pop 3)Display : ");
        scanf("%d",&ch);
        if (ch==1)
        {
            printf("Enter element : ");
            int x;
            scanf("%d",&x);
            push(s,x);
        }
        else if (ch==2)
        {
            printf("Popped : %d",pop(s));
        }
        else if (ch=3)
        {
            display(s);
        }
        else
        {
            ch=4;
            break;
        }
    }while(ch<4);
}