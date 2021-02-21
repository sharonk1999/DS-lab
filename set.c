//Universal Set is {1,2,3,4,5,6,7,8,9}
#include &lt;stdio.h&gt;
void Input();
void Display();
void Union();
void Intersection();
void Difference();
int a[]={0,0,0,0,0,0,0,0,0};
int b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0};
void main()
{
    int ch;
    clrscr();
    printf(&quot;********************SET OPERATIONS********************\n&quot;);
    do
    {
        
        printf(&quot;1.Input\n2.Union\n3.Intersection\n4.Difference\n5.Exit\n&quot;);
        printf(&quot;Enter choice    :   &quot;);
        scanf(&quot;%d&quot;,&amp;ch);
        switch(ch)
        {
            case 1:Input();break;
            case 2:Union();break;
            case 3:Intersection();break;
            case 4:Difference();break;
            case 5:exit(0);
            default:printf(&quot;\n***********invalid choice********\n&quot;);
        }
    }while(ch!=5);
}
void Input() 
{
    int n1,n2,x,i;
    printf(&quot;\nEnter size of SET 1 :   &quot;);
    scanf(&quot;%d&quot;,&amp;n1);

    printf(&quot;Enter elements of SET 1   :   &quot;);
    for(i=1;i&lt;=n1;i++)
    {
        scanf(&quot;%d&quot;,&amp;x);
        a[x]=1;
    }
    printf(&quot;\nEnter size of SET 2   :   &quot;);
    scanf(&quot;%d&quot;,&amp;n2);
    printf(&quot;Enter elements of SET 2   :   &quot;);
    for(i=1;i&lt;=n2;i++)
    {
        scanf(&quot;%d&quot;,&amp;x);
        b[x]=1;
    }
    printf(&quot;\nSET 1 :   {&quot;);
    for(i=1;i&lt;=9;i++)
    {
        printf(&quot;%d  &quot;,a[i]);
    }
    printf(&quot;}&quot;);
    printf(&quot;\nSET 2 :   {&quot;);
    for(i=1;i&lt;=9;i++)
    {
        printf(&quot;%d\t&quot;,b[i]);
    }
     printf(&quot;}&quot;);
}
void Display(int c[])
{
    int i;
    printf(&quot;\n\t\t{&quot;);
    for(i=1;i&lt;=9;i++)
    {
       if (c[i]!=0)
       printf(&quot;%d  &quot;,i);
    }
    printf(&quot;}&quot;);   
}
void Union()
{
  int c[10],i;
  for(i=1;i&lt;=9;i++) 
  {
    if(a[i]!=b[i])
        c[i]=1;
    else
        c[i]=a[i];
  }

  printf(&quot;\nSET is :   {&quot;);
  for(i=1;i&lt;=9;i++)  
    {
        printf(&quot;%d  &quot;,c[i]);
    }
  printf(&quot;}&quot;);
   Display(c);
}
void Intersection()
{
  int c[10],i;
  for(i=1;i&lt;=9;i++)
  {
    if (a[i]==b[i])
        c[i]=a[i];
    else
        c[i]=0;
  }
  printf(&quot;\nSET is :   {&quot;);
  for(i=1;i&lt;=9;i++)
  {
    printf(&quot;%d  &quot;,c[i]);
  }
  printf(&quot;}&quot;);
  Display(c);
}
void Difference()
{
  int c[10],i;
  for(i=1;i&lt;=9;i++)
  {
    if (a[i]==1 &amp;&amp; b[i]==0)
        c[i]=1;
    else
        c[i]=0;
  }
  printf(&quot;\nSET is :   {&quot;);
  for(i=1;i&lt;=9;i++)
  {
    printf(&quot;%d  &quot;,c[i]);
  }
  printf(&quot;}&quot;);
  Display(c);
}