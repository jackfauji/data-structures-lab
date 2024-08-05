#include<stdio.h>
#define max 10
void push(int [],int *);
void pop(int [],int *);
void display(int [],int);
void peek(int [],int);
int main()
{
	int i,n,top=-1,stack[max];
	do{
		printf("1.push  2.pop   3.display   4.seek  5.stop: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				push(stack,&top);
				break;
			}
			case 2:
			{
				pop(stack,&top);
				break;
			}
			case 3:
			{
				display(stack,top);
				break;
			}
			case 4:
			{
				peek(stack,top);
				break;
			}	
 		}}while(n<=4);
}
void push(int stack[],int *p)
{
	int x;
	if(*p==max-1)
	{
		printf("\nstack overflow/stack is full\n");
	}
	else{
		printf("\nenter a number to push :");
		scanf("%d",&x);
		*p=*p+1;
		stack[*p]=x;
		return;
	}
}
void pop(int stack[],int *p)
{
	int x;
	if(*p==-1)
	{
		printf("\nstack underflow/stack is empty\n");
	}
	else{
		x=stack[*p];
		printf("\nthe popped element is : %d",x);
		*p=*p-1;
	}
}
void display(int stack[],int top)
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
void peek(int stack[],int top)
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else{
		printf("%d ",stack[top]);
	}
	printf("\n");
}
		
