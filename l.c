#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}sn;
sn* insert(sn *head)
{
    sn *newnode;
    newnode=(sn*)malloc(sizeof(sn));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    return head;
}

int main()
{
	sn *head,*newnode=0,*temp=0;
	head=0;
	int ch=1;
	while(ch)
	{
		newnode=(sn*)malloc(sizeof(sn));
		printf("enter data to store");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0)
		{
			head=newnode;
			temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		printf("do you want to (0,1)?");
		scanf("%d",&ch);
	}
	head=insert(head);
	temp=head;
	
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}	
	
