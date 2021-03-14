#include<stdio.h>;
#include<conio.h>;
void insertTree(int);
void displayTree();
struct bstNode
{
 struct tnode *left;
 int data;
 struct tnode *right;
};
typedef struct bstNode tnode;
tnode *root= NULL;  
tnode *getnode(int);
tnode *deleteTree(tnode*,int);
void searchTree(tnode*,int);
tnode* getnode(int item)
{   
    tnode *newNode = (tnode *)malloc(sizeof(tnode));  
    newNode->data= item;
    newNode->left = NULL;  
    newNode->right = NULL;     
    return newNode;  
}  
void main()
{
     int ch;
    printf("\n**********************BINARY SEARCH TREE OPERATIONS*********************");
    while (1)
    {
         printf("\n1.Insert");
        printf("n2.Delete");
        printf("\n3.Search");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        {
            int item;
            printf("\nEnter the element :   ");
               scanf("%d",&item);
            insertTree(item);
            break;
        }
        case 2: 
        {
            int item;
            printf("\nEnter the element to be deleted   :   ");
            scanf("%d",&item);
            deleteTree(root,item);
            break;
        }   
        case 3: 
        {
            int item;
            printf("Enter search element  :   ");
            scanf("%d",&item);
            searchTree(root,item);
            break;
        }   
        case 4: 
        {
            displayTree(root,1);
            break;
        }   
        case 5:        
            exit(0);
        default :     
            printf("Wrong choice, Please enter correct choice ");
            break;    
        }
    }
    
}
void insertTree(int item) 
{    
    tnode *newNode = getnode(item);  
      
   
    if(root == NULL)
    {  
        root = newNode;  
        return;  
    }
else 
    {  
        tnode *current = root, *prev = NULL;  
          
    while(1)
        {   
            prev = current;  
            if(item < current->data) 
            {  
                current = current->left;  
                if(current == NULL) 
                {  
                    prev->left = newNode;  
                    return;  
                }  
            }  
            
            else 
            {
                current = current->right;  
                if(current == NULL) 
                {  
                    prev->right = newNode;  
                    return; 
                } 
            }  
        }  
        
    }  
}  
void displayTree(tnode *root,int level)
{
  int i;
 
  if((root)!=NULL)
  {
    displayTree((root)->right,level+1);
    printf("\n\n");
    for(i=0;i<level;i++)
        printf("    ");
    printf("%d",(root)->data);
    displayTree((root)->left,level+1);
  }
}
tnode* minNode(tnode *root) {  
    if (root->left != NULL)  
        return minNode(root->left);
else   
        return root;  
}   
tnode* deleteTree(tnode *temp, int value) {  
    if(temp == NULL)
    {  
        printf("\nTree is Empty!!!");
        return ;  
    }  
    else 
    {  
        if(value < temp->data)  
            temp-&gt;left = deleteTree(temp-&gt;left, value);  
          
         
        else if(value &gt; temp-&gt;data)  
            temp-&gt;right = deleteTree(temp-&gt;right, value);  
          
        
        else 
        {  
             
            if(temp-&gt;left == NULL &amp;&amp; temp-&gt;right == NULL)  
                temp = NULL;  
                
            else if(temp-&gt;left == NULL) 
                temp = temp-&gt;right;  
              
            else if(temp-&gt;right == NULL) 
                temp = temp-&gt;left;  
            
              
            else 
            {  
                tnode *ptr = minNode(temp-&gt;right);  
                temp-&gt;data = ptr-&gt;data;   
                temp-&gt;right = deleteTree(temp-&gt;right, ptr-&gt;data);  
            }  
        }  
        return temp;
    }  
}  
void searchTree(tnode *root,int item)
{
  if(root == NULL ) 
    {
        printf(&quot;TREE IS EMPTY!!&quot;);

        return;
    }
   if(item == root-&gt;data )
   {
       printf(&quot;\nElement found in the tree!!&quot;);
       return ;
   }
       
    else if(item&lt; root-&gt;data )
    {
        searchTree(root-&gt;left);
        return;
    }   
    else if(item &gt; root-&gt;data) 
    {
        searchTree(root-&gt;right);
        return;
    }
    else
    {
        printf(&quot;\nElement not found in the tree&quot;);
    }
    
       
}