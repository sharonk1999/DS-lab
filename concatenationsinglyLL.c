#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node Node;
Node *h1,*h2;

Node *getNode()
{
    Node *n;
    n=(Node *)malloc(sizeof(Node));
    return n;
}
void input(int n,Node **head)
{
    Node *newNode,*curr;
    int i, item;
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        newNode=getNode();
        if(newNode==NULL)
        {
	        printf("NO EMPTY NODE!!!");
	        return;
        }
        newNode->data=item;
        newNode->link=NULL;
        if(*head==NULL)
	        *head=newNode;
        else
        {
	        curr=*head;
	        while(curr->link!=NULL)
	             curr=curr->link;
	        curr->link=newNode;
        }
    }
}
void display(Node **head)
{
    Node *temp=*head;
    while(temp->link!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->link;
    }
    printf("%d->NULL\n",temp->data) ;
}
Node *concat(Node **h1,Node **h2)
{
    Node *ptr;
	if(*h1==NULL)
	{
	    *h1=*h2;
	    return *h1;
	}
	if(*h2==NULL)
		return *h1;
	ptr=*h1;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	ptr->link=*h2;
	return *h1;
}
void main()
{
    int n1,n2;
    clrscr();
    printf("\n\t*********CONCATENATION OF  SINGLY LINKED LIST********\n");
    printf("\nEnter size of 1st linked list : ");
    scanf("%d",&n1);
    printf("Enter elements of 1st linked list : ");
    input(n1,&h1);
    printf("Enter size of 2nd linked list : ");
    scanf("%d",&n2);
     printf("Enter elements of 1st linked list : ");
    input(n2,&h2);
    printf("\nSINGLY LINKED LIST 1 : ");
    display(&h1);
    printf("\nSINGLY LINKED LIST 1 : ");
    display(&h2);
    printf("\nConcatenated Linked list : ");
    h1 =concat(&h1,&h2);
    display(&h1);
    getch();
}