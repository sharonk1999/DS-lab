#include<stdio.h>
#include<conio.h>
void createList();
void displayList();
struct node
{
 int data;
 struct node *link;
};
struct node *head;
void main()
{
 int n;
 clrscr();
 printf("Enter the number of nodes : ");
 scanf("%d",&n);
 createList(n);
 printf("The linear linked list : ");
 displayList();
 getch();
}
void createList(int n)
{
 struct node *temp,*ptr;
 int i;
 for(i=0;i<n;i++)
 {
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
 printf("Overflow\n");
 exit(0);
}

 printf("nEnter Node %d data : ",i+1);
 scanf("%d",&temp->data);
 temp->link=NULL;
 if(head==NULL)
 {
 head=temp;
 }
 else
 {
 ptr=head;
 while(ptr->link!=NULL)
 {
 ptr=ptr->link;
 }
 ptr->link=temp;
 }
 }
}
void displayList()
{
 struct node *ptr;
 if(head==NULL)
 {
 printf("Underflow\n");
 }
 else
 {
 ptr=head;
 while(ptr!=NULL)
 {
 printf("%d\t",ptr->data );
 ptr=ptr->link ;
 }
 }
}