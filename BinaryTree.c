#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* rchild;
    struct node* lchild;
};
struct node* createnode()
{
    int x;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter element : "); //take element
    scanf("%d",&x); 
    if (x==-1) //if we that is a leaf node, give -1, will return NULL as address
        return(NULL);
    newnode->data=x; //else take input and continue recursion
    printf("Enter Left Child of %d",x);
    newnode->lchild=createnode(); //traverses until leaf of left(-1), from where the lhild addresses will be inherited
    printf("Enter Right Child of %d",x);
    newnode->rchild=createnode(); //similarly traverses until leaf of right(-1), from where address inherited upwards.
    return(newnode); //ultimate final return will be the root node (must be assigned in main)
}
void preorder(struct node* root) // Root | Left | Right
{
    if (root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(struct node* root) // Left | Right | Root
{
    if (root==NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
}
void inorder(struct node* root) //Left | Root | Right
{
    if (root==NULL)
        return;
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
}
void insert(struct node* root,char loc[])
{
    int x,i=0;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* parent,*curr; //curr points to a child
    printf("Enter element : "); //take element
    scanf("%d",&x);
    newnode->data=x;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    curr=root; //for child
    parent=NULL; //we are going to find location of parent
    while(loc[i]&&curr)
    {
        parent=curr; //parent updated to child as child will be subsequently updated
        if(loc[i]=='L')
            curr=curr->lchild;
        else
            curr=curr->rchild;
        i++; //i successively points to last
    }
    if (curr!=NULL||loc[i]!='\0') //either the child is occupied or i is now pointing to last, if it is not endline.
    {
        printf("Not Insertable");
        free(newnode);
        return;
    }
    if (loc[i-1]=='L') //check with last element and store as PARENTS child
        parent->lchild=newnode;
    else
        parent->rchild=newnode;
}
int main()
{
    struct node BT;
    struct node*root=NULL;
    int ch=0;
    char loc[10];
    root=createnode();
    do
    {
        printf("Enter what you want to do : 1) 2) 3) 4) 5)");
        scanf("%d",&ch);
        if (ch==1)
        {
            preorder(root);
        }
        else if (ch==2)
        {
            postorder(root);
        }
        else if (ch==3)
        {
            inorder(root);
        }
        else if (ch==4)
        {
            insert(root,"LL");
        }
        else
            ch=99;
    }while (ch<=4);
}