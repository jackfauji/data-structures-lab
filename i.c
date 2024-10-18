#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}sn;

sn * create(sn *);
void maxmin(sn*);
void display(sn *);
sn *split(sn *);

int main()
{
	sn* head=NULL,*head1=NULL;
	head=create(head);
	display(head);
	maxmin(head);
	head1=split(head);
	display(head1);

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


void maxmin(sn *head)
{
	int max=0,min=0;
	max=head->data;
	min=head->data;
	while(head!=NULL)
	{
		if(head->data>max)
			max=head->data;
		if(head->data<min)
			min=head->data;
		head=head->next;
	}
	printf("the maximum value is : %d\n",max);
	printf("the minimum value is : %d\n",min);
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

sn * split(sn*head)
{
	sn*head1=NULL,*temp=NULL,*newnode=NULL;
	if(head==NULL)
		printf("empty");
	else{
		while(head!=NULL)
		{
			if((head->data%2)==0)
			{
				newnode=(sn*)malloc(sizeof(sn));
				newnode->data=head->data;
				newnode->next=NULL;
				if(head1==NULL)
					head1=temp=newnode;
				else{
					temp->next=newnode;
					temp=newnode;
				}
			}
			head=head->next;
		}
	}
	return head1;
}
