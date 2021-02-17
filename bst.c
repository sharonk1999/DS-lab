#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
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
    newNode-&gt;data= item;
    newNode-&gt;left = NULL;  
    newNode-&gt;right = NULL;     
    return newNode;  
}  
void main()
{
     int ch;
    printf(&quot;\n**********************BINARY SEARCH TREE OPERATIONS*************
********&quot;);
    while (1)
    {
         printf(&quot;\n1.Insert&quot;);
        printf(&quot;\n2.Delete&quot;);
        printf(&quot;\n3.Search&quot;);
        printf(&quot;\n4.Display&quot;);
        printf(&quot;\n5.Exit&quot;);
        printf(&quot;\nEnter your choice : &quot;);
        scanf(&quot;%d&quot;, &amp;ch);
        switch (ch)
        {
        case 1:
        {

            int item;
            printf(&quot;\nEnter the element :   &quot;);
                scanf(&quot;%d&quot;,&amp;item);
            insertTree(item);
            break;
        }    
        case 2: 
        {
            int item;
            printf(&quot;\nEnter the element to be deleted   :   &quot;);
            scanf(&quot;%d&quot;,&amp;item);
            deleteTree(root,item);
            break;
        }   
        case 3: 
        {
            int item;
            printf(&quot;Enter search element  :   &quot;);
            scanf(&quot;%d&quot;,&amp;item);
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
            printf(&quot;Wrong choice, Please enter correct choice  &quot;);
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
            if(item &lt; current-&gt;data) 
            {  
                current = current-&gt;left;  
                if(current == NULL) 
                {  
                    prev-&gt;left = newNode;  
                    return;  
                }  
            }  
            
            else 
            {
                current = current-&gt;right;  
                if(current == NULL) 
                {  
                    prev-&gt;right = newNode;  
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
    displayTree((root)-&gt;right,level+1);
    printf(&quot;\n\n&quot;);
    for(i=0;i&lt;level;i++)
        printf(&quot;      &quot;);
    printf(&quot;%d&quot;,(root)-&gt;data);
    displayTree((root)-&gt;left,level+1);
  }
}
tnode* minNode(tnode *root) {  
    if (root-&gt;left != NULL)  
        return minNode(root-&gt;left);  

    else   
        return root;  
}   
tnode* deleteTree(tnode *temp, int value) {  
    if(temp == NULL)
    {  
        printf(&quot;\nTree is Empty!!!&quot;);
        return ;  
    }  
    else 
    {  
        if(value &lt; temp-&gt;data)  
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