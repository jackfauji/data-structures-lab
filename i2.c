#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}sn;

sn * create(sn *);
sn * createcl(sn *);
int detectloop(sn *);
void display(sn*);
void displaycl(sn*);

int main()
{
	sn *head=NULL,*head1=NULL;
	head=create(head);
	display(head);
	head1=createcl(head1);
	display(head1);
	int x=detectloop(head);
	if(x==0)
		printf("no loop\n");
	else{
		printf("loop detected\n");
		}
	int y=detectloop(head1);
	if(x==0)
		printf("no loop\n");
	else{
		printf("loop detected\n");
		}
}

sn* create(sn *head)
{
	sn *head1=NULL,*temp=NULL,*newnode=NULL;
	int ch;
	do{
			newnode=(sn*)malloc(sizeof(sn));
			printf("enter data");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			if(head1==NULL)
			{
				head1=temp=newnode;
			}
			else{
				temp->next=newnode;
				temp=newnode;
			}
			printf("want more node(0,1)");
			scanf("%d",&ch);
		}while(ch!=0);
		return head1;
}

int detectloop(sn* head)
{
	sn *slow=head,*fast=head;
	while(slow!=NULL && fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			return 1;
		}
	}
	return 0;
}	

sn* createcl(sn *head)
{
	sn *head1=NULL,*temp=NULL,*newnode=NULL;
	int ch;
	do{
			newnode=(sn*)malloc(sizeof(sn));
			printf("enter data");
			scanf("%d",&newnode->data);
			if(head1==NULL)
			{
				head1=temp=newnode;
			}
			else{
				temp->next=newnode;
				temp=newnode;
			}
			newnode->next=head1;
			printf("want more node(0,1)");
			scanf("%d",&ch);
		}while(ch!=0);
		return head1;
}

void display(sn* head)
{
	if(head==NULL)
		printf("empty");
	else{
		while(head!=NULL)
		{
			printf("%d ",head->data);
			head=head->next;
		}
		printf("\n");
	}
}
void displaycl(sn* head)
{
	sn*temp=head;
	if(head==NULL)
		printf("empty");
	else{
		do
		{
			printf("%d ",head->data);
			head=head->next;
		}while(head!=temp);
		printf("\n");
	}
}
