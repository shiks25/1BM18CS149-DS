#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE getnode();
NODE insert(NODE head,int item,int *count,int size);
NODE delete(NODE head);
void display(NODE head);
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("memory could not be allocated\n");
		exit(0);
	}
}
NODE insert(NODE head,int item,int *count,int size)
{
	NODE p,q;
	if(*count<=size)
	{
	q=getnode();
	q->data=item;
	q->next=NULL;
	if(head==NULL)
		return q;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	}
	else
	{
		printf("Queue overflow\n");
	}
	return head;
	
}
NODE delete(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("Queue underflow\n");
		return head;
	}
	printf("Deleted element = %d\n", p->data);
	head=p->next;
	free(p);
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n", p->data);
		p=p->next;
	}
}
int main()
{
	NODE head=NULL;
	int ch,item,count,size;
	count=1;
	printf("enter the size of the queue\n");
	scanf("%d",&size);
	printf("enter\n1.insert\n2.delete\n3.display\n-1.exit\n");
	scanf("%d",&ch);
	while(ch!=-1)
	{
		switch(ch)
		{
			case 1:printf("enter the item\n");
				scanf("%d",&item);
				head=insert(head,item,&count,size);
				count++;
				break;
			case 2:head=delete(head);
				break;
			case 3:display(head);
				break;
			default:printf("invalid input\n");
		}
		printf("enter next choice or -1 to exit\n");
		scanf("%d",&ch);
	}
	return 0;
}

