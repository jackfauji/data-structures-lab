#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}sn;

sn * create()
{
	sn* head=NULL,*newnode=NULL,*temp=NULL;
	int ch=1;
	while(ch)
	{
		newnode=(sn*)malloc(sizeof(sn));
		printf("enter data :");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
			head=temp=newnode;
		else{
			temp->next=newnode;
			temp=newnode;
		}
		printf("do u want to add node(0,1) ");
		scanf("%d",&ch);
	}
	return head;
}
void sort(sn * head)
{
	int x;
	sn *ptr=NULL,*cpt=NULL;
	ptr=head;
	while(ptr->next!=NULL)
	{
		 cpt=ptr->next;
		 while(cpt!=NULL)
		 {
			if(ptr->data>cpt->data)
			{
				x=ptr->data;
				ptr->data=cpt->data;
				cpt->data=x;
			}
			cpt=cpt->next;
		}
		ptr=ptr->next;
	}
}

void display(sn * head)
{
	sn *temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	sn *head=NULL;
	head=create();
	display(head);
	sort(head);
	display(head);
}

		
	

