#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * next;
}sn;
 sn * create()
 {
	sn *head=NULL,*temp=NULL,*newnode=NULL;
	int ch;
	do{
		newnode=(sn*)malloc(sizeof(sn));
		if(newnode!=NULL)
		{
			printf("enter data");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			if(head==NULL)
			{
				head=temp=newnode;
			}
			else{
				temp->next=newnode;
				temp=newnode;
			}
		}
		printf("do u want to add newnode(0,1)");
		scanf("%d",&ch);
	}while(ch!=0);
	return head;
}

void display(sn * head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

sn* alternatenode(sn* head1,sn* head2)
{
	sn *head3=NULL,*temp=NULL,*newnode=NULL;
	while(head1!=NULL && head2!=NULL)
	{
		newnode=(sn*)malloc(sizeof(sn));
		if(head1!=NULL)
		{
			newnode->data=head1->data;
			head1=head1->next;
		}
		newnode->next=NULL;
		
        	newnode->next = NULL;
        	if (head3 == NULL) {
        	 	head3 = temp = newnode;
        	} 
        	else {
            	temp->next = newnode;
            	temp = newnode;
        	}
        	
        	if(head2!=NULL)
        	{
			newnode=(sn*)malloc(sizeof(sn));
			newnode->data=head2->data;
			head2=head2->next;
		}
		newnode->next = NULL;
        	if (head3 == NULL) {
        	 	head3 = temp = newnode;
        	} 
        	else {
            	temp->next = newnode;
            	temp = newnode;
        	}		
		
	}
	while(head1!=NULL)
	{
		newnode=(sn*)malloc(sizeof(sn));
		newnode->data=head1->data;
		head1=head1->next;
		newnode->next = NULL;
        	if (head3 == NULL) {
        	 	head3 = temp = newnode;
        	} 
        	else {
            	temp->next = newnode;
            	temp = newnode;
      	}
      }
      while(head2!=NULL)
	{
		newnode=(sn*)malloc(sizeof(sn));
		newnode->data=head2->data;
		head2=head2->next;
		newnode->next = NULL;
        	if (head3 == NULL) {
        	 	head3 = temp = newnode;
        	} 
        	else {
            	temp->next = newnode;
            	temp = newnode;
      	}
      }
	return head3;
}

int main()
{
	sn * head1=NULL,*head2=NULL,*head3=NULL;
	head1=create();
	head2=create();
	head3=alternatenode(head1,head2);
	display(head1);
	display(head2);
	display(head3);
}
	
