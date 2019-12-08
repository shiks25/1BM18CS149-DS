#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE p=(NODE)malloc(sizeof(struct node));
    if(p!=NULL)
        return p;
    else
       exit(0);
}
NODE insert_front(NODE head,int item)
{
    
    NODE p=getnode();
    p->data=item;
    if(head==NULL){
        p->next=p;
        head=p;
    }
    else
    {
    NODE q=head->next;
    p->next=q;
    head->next=p;
    }
    return head;
}
NODE insert_end(NODE head,int item)
{
    
    NODE x=getnode();
    x->data=item;
    NODE t=head->next;
    head->next=x;
    x->next=t;
    head=x;
    return head;
    
}
NODE add_nos(NODE h1,NODE h2)
{
    NODE f = NULL;
    
    int sum=0,carry=0;
    int pn1,pn2,res;
    NODE p=h1->next,q=h2->next;
    
    while(p!=h1 && q!=h2)
    {
        if(p==h1)
        {
           
              pn1=0;
              
            
        }
        else
           pn1=p->data;
        if(q==h2)
        {
           
              pn2=0;
              
           
        }
            
        else
           pn2=q->data;
        
        res=pn1+pn2+carry;
        
        carry=res/10;
        f=insert_front(f,res%10);
       
           p=p->next;
        
           q=q->next;
    }
    
    res=p->data+q->data+carry;
    f=insert_front(f,res);
    return f;
}

void display(NODE head)
{
    if(head==NULL)
    {
        printf("you loser\n");
    }
    NODE x=head->next;
    while(x!=head)
    {
        printf("%d\n",x->data);
        x=x->next;
    }
    printf("%d\n",x->data);
}
int main()
{
    int ele,n1,n2,i;
    NODE head1=NULL,head2=NULL,add;
    printf("enter the no. of digts for num1\n");
    scanf("%d",&n1);
    printf("enter num1\n");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&ele);
        head1=insert_front(head1,ele);
    }
    printf("enter the no. of digits for num2\n");
    scanf("%d",&n2);
    
    printf("enter num2\n");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&ele);
        head2=insert_front(head2,ele);
    }
    if(n1>n2)
    {
        for(i=0;i<n1-n2;i++)
        {
            head2=insert_end(head2,0);
        }
    }
    if(n2>n1)
    {
        for(i=0;i<n2-n1;i++)
        {
            head1=insert_end(head1,0);
        }
    }
    
    add=add_nos(head1,head2);
    display(add);

    return 0;
}
