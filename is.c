#include<stdio.h>
#include<stdlib.h>
void push(int *stk,int *top,int n);
void pop(int *stk,int *top);
void display(int *stk,int top);
void peek(int * stk,int top);
int main()
{
	int *ptr,top=-1,n,ch;
	printf("enter numbers you want to store");
	scanf("%d",&n);
	ptr=(int*)malloc(n*sizeof(int));
	do{
		printf("1.push  2.pop   3.display   4.seek  5.stop: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				push(ptr,&top,n);
				break;
			}
			case 2:
			{
				pop(ptr,&top);
				break;
			}
			case 3:
			{
				display(ptr,top);
				break;
			}
			case 4:
			{
				peek(ptr,top);
				break;
			}	
 		}}while(ch<=4);
}
void push(int *stk,int *top,int n)
{
	int x;
	if(*top==n-1)
	{
		printf("\nstack overflow/stack is full\n");
	}
	else{
		printf("\nenter a number to push :");
		scanf("%d",&x);
		*top=*top+1;
		*(stk+*(top))=x;
		return;
	}
}
void pop(int *stk,int *top)
{
	int x;
	if(*top==-1)
	{
		printf("\nstack underflow/stack is empty\n");
	}
	else{
		x=*(stk+*(top));
		printf("\nthe popped element is : %d",x);
		*top=*top-1;
	}
}
void display(int *stk,int top)
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d ",*(stk+i));
	}
	printf("\n");
}
void peek(int * stk,int top)
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else{
		printf("%d ",*(stk+top));
	}
	printf("\n");
}
		
