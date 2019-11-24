#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE getnode();
NODE push(int item,NODE head,int *count,int size);
NODE pop(NODE head);
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
NODE push(int item,NODE head,int *count,int size)
{
	NODE p;
	if(*count<=size)
	{
		p=getnode();
		p->data=item;
		p->next=head;
		head=p;
	}
	else
	{
		printf("Stack overflow\n");
	}
	return head;
}
NODE pop(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("Stack underflow\n");
		return head;
	}
	printf("Popped element = %d\n", p->data);
	head=p->next;
	free(p);
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("stack is empty\n");
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
	printf("enter the size of the stack\n");
	scanf("%d",&size);
	printf("enter\n1.push\n2.pop\n3.display\n-1.exit\n");
	scanf("%d",&ch);
	while(ch!=-1)
	{
		switch(ch)
		{
			case 1:
 				  printf("enter the item\n");                                                        
                                          scanf("%d",&item);
				   head=push(item,head,&count,size);
                                          count++;
                                    break;
			case 2:head=pop(head);
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


