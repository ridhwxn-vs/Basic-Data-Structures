#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* createnode()
{
    struct node* newnode;
    int d;
    newnode =(struct node*) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&d);
    newnode->data=d;
    newnode->next=NULL;
    return(newnode);
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
    //CREATING AND ADDING EACH NODES UNTIL USERS SELECTS DONE
    while(choice==1)
    {
        struct node* new;
        new =(struct node*) malloc(sizeof(struct node));
        struct node* temp;
        new=createnode(); //newnode created with default values
        if (head==NULL)
        {
            head=new;
            temp=new;//if empty both head and temp to point to first element
        }
        else
        {
            temp->next=new;//else current temp's next->newnode and temp=newnode.
            temp=new;
        }
        //temp->next=head; #This makes it Circular Linked List
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
            struct node* new=(struct node*) malloc(sizeof(struct node));
            new=createnode();
            if (head==NULL)
                head=new;
            else
            {
                new->next=head;//current head is second, so next of new element
                head=new;//new head is new node
            }
        }
        else if (ch2==2)
        {
            //END INSERT
            struct node* new=(struct node*) malloc(sizeof(struct node));
            struct node* temp;
            new=createnode();
            if (head==NULL)
                head=new;
            else
            {   
                temp=head;
                while (temp->next!=NULL)//if we use temp, then we cannot use next(temp will be NULL)
                {
                    temp=temp->next;//points to last element
                }
                temp->next=new;//newnode added after last element
            }
        }
        else if (ch2==3)
        {
            //POSITION INSERT
            int pos,i=0;
            struct node* new=(struct node*) malloc(sizeof(struct node));
            struct node* temp;
            new=createnode();
            printf("Enter position : ");
            scanf("%d",&pos);
            temp=head;
            while (i<pos)
            {
                temp=temp->next;
                i++;//finding position
            }
            new->next=temp->next;//first must update newnodes next otherwise one will be disconnected
            temp->next=new;//now element before newnode must point to it
        }
        else if(ch2==4)
        {
            //BEGINNING DELETE
            struct node* temp;
            temp=head;
            head=head->next;//current head to be deleted, so head points to next.
            free(temp);//temp is current head, free its memory.
        }
        else if(ch2==5)
        {
            //END DELETE
            struct node* temp;
            struct node* prev;
            temp=head;
            while(temp->next!=NULL)
            {
                prev=temp;//Prev required to set its next as null and free the temp
                temp=temp->next;
            }
            prev->next=NULL;
            free(temp);//temp is disconnected and freed.
        }
        else if(ch2==6)
        {
            //POSITION DELETE
            struct node*temp;
            struct node*nextn;
            int pos,i=1;
            printf("Enter position to delete : ");
            scanf("%d",&pos);
            temp=head;
            while(i<pos-1)//this is why we use nextnode(Pos-1)
            {
                temp=temp->next;
                i++;//get position
            }
            nextn=temp->next;//this is node to delete
            temp->next=nextn->next;//nextn address being changed
            free(nextn);//nextn now disconnected,is freed
        }
        else if(ch2==7)
        {
            display(head);
        }
        else if(ch2==8)
        {
            struct node *prev,*curr,*nex;
            prev=NULL;
            curr=nex=head;
            while(nex!=NULL)
            {
                nex=nex->next;//prev current and next now correct
                curr->next=prev;//-> converted to <-
                prev=curr;//convoy moving forward converting each arrow
                curr=nex;
            }
            head=prev;//prev now last element, which is new head.
        }
    }while (ch2<=8);
    return(0);
}