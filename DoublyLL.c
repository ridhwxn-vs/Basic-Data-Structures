#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* createnode()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
}
void display(struct node* head)
{
    struct node* temp;
    temp=head;
    if (head==NULL)
        printf("No Elements");
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("X");
}
int main()
{
    struct node* head=NULL;
    int choice=1;
    while(choice==1)
    {
        struct node* temp,*new;
        new=(struct node*) malloc(sizeof(struct node));
        new=createnode();
        if (head==NULL)
        {
            head=temp=new;//if first element, head temp are both newnode
            //For Circular DLL, both next and prev to be pointing to head.
        }
        else
        {
            temp->next=new;//current element's next will point to  new element
            new->prev=temp;//new element's previous points to current element
            temp=new;//now temp is shifted
            //for Circular DLL, 5 updations in total, Head's Previous and End's Next.
        }
        printf("Press 1 to continue : ");
        scanf("%d",&choice);
    }
    printf("\nDisplaying...\n");
    display(head);
    int ch2;
    do
    {
        printf("\nChoice : 1)Insert at beg 2)Insert at end 3)Insert at position 4)Delete from beg 5)Delete from end 6)Delete from pos 7)Display 8)Invert");
        scanf("%d",&ch2);
        if (ch2==1)
        {
            //BEGINNING INSERT
            struct node *new;
            new=(struct node*) malloc(sizeof(struct node));
            new=createnode();
            new->next=head;//update new nodes next to current head
            head->prev=new;//update old heads prev as new node
            head=new;//update new head
        }
        else if (ch2==2)
        {
            //END INSERT
            struct node* temp,*new;
            new=(struct node*) malloc(sizeof(struct node));
            new=createnode();
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;//find end
            new->prev=temp;//new end's prev must old end
            temp->next=new;//old end's next is newnode
        }
        else if (ch2==3)
        {
            //POSITION INSERT
            struct node* temp,*new;
            new=(struct node*) malloc(sizeof(struct node));
            new=createnode();
            int pos,i=1;
            printf("Enter position :");
            scanf("%d",&pos);
            temp=head;
            while(i<pos-1)
            {
                temp=temp->next;
            }
            new->prev=temp;
            new->next=temp->next;//update newnodes next and prev
            temp->next=new;
            new->next->prev=new;//next nodes previous to new node
        }
        else if(ch2==4)
        {
            //BEGINNING DELETE
            struct node* temp;
            temp=head;
            head=head->next;//same as single
            head->prev=NULL;//must change new head's previous as NULL
            free(temp);
        }
        else if(ch2==5)
        {
            //END DELETE
            struct node* temp,*prev;
            temp=head;
            while(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;//reach end and keep previous
            }
            prev->next=NULL;//previous is now new end, so its next is null
            free(temp);
        }
        else if(ch2==6)
        {
            //POSITION DELETE
            struct node* temp,*prev;
            int pos,i=1;
            temp=head;
            printf("Enter position :");
            scanf("%d",&pos);
            while(i<pos)
            {
                temp=temp->next;
                i++;//find position
            }
            temp->prev->next=temp->next;//previous node's next is now current's next
            temp->next->prev=temp->prev;//next node's previous is now current's previous
            free(temp);
        }
        else if(ch2==7)
        {
            display(head);
        }
        else if(ch2==8)
        {
            struct node *temp,*nextn;
            temp=head;
            nextn=temp->next;
            head->next=NULL; //reverse head pointer
            head->prev=nextn;
            while(nextn!=NULL)
            {
                nextn->prev=nextn->next;
                nextn->next=temp;
                temp=nextn;
                nextn=nextn->prev;//nextn is going back until it reaches NULL
            }
            head=temp;
        }
    }while (ch2<=8);
    return(0);
}