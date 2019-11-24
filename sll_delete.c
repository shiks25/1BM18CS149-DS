#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE delete_front(NODE head);
NODE delete_end(NODE head);
NODE delete_ele(NODE head, int ele);
void display(NODE head);
NODE getnode();
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

void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n", p->data);
		p=p->next;
	}
}
NODE delete_front(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	printf("Deleted element = %d\n", p->data);
	head=p->next;
	free(p);
	return head;
}
NODE delete_end(NODE head)
{
	NODE p=head;
	NODE q=p;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(head->next==NULL)
	{
		printf("Deleted ele=%d\n",head->data);
		free(head);
		return NULL;
	}

	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	printf("Deleted elemnets = %d\n", p->data);
	free(p);	
	return head;
}
NODE delete_ele(NODE head, int ele)
{
	NODE curr=head;
	NODE prev=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}	
	if(head->data==ele)
	{
		
		printf("deleted elements = %d\n", head->data);
		curr=head;
		head=head->next;
		free(curr);
			
		return head;
	}
	else
	{
		while(curr!=NULL && curr->data!=ele)
		{
			prev=curr;
			curr=curr->next;
		}
		
		if(curr==NULL)
		{
			printf("value does not exist\n");
			return head;
		}
		else
		{
			prev->next=curr->next;
			printf("deleted element =%d\n",curr->data);
			free(curr);
			return head;
		}
	}
	
}
int main()
{
	int data; 
	NODE p,q,r;
	NODE head=NULL;
	head=getnode();
	int ch,ele;
	printf("Enter\n1.delete front\n2.delete a given element\n3.delete end\n4.Display\n-1.Exit\n");
	scanf("%d",&ch);
	head->data=1;
	p=getnode();
	head->next=p;
	p->data=2;
	q=getnode();
	p->next=q;
	q->data=3;
	r=getnode();
	q->next=r;
	r->data=4;
	r->next=NULL;
	while(ch!=-1)
	{
		switch(ch)
		{
			case 1:head=delete_front(head);
				break;
			case 2:printf("enter the element\n");
				scanf("%d",&ele);
				head=delete_ele(head,ele);
				break;
			case 3:head=delete_end(head);
				break;
			case 4:display(head);
				break;
			default:printf("invalid input\n");
		}
		printf("enter next choice or -1 to exit\n");
		scanf("%d",&ch);
	}
	return 0;
}