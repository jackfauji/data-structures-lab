#include<stdio.h>
#define max 10
int enq(int [],int);
int deq(int [],int ,int);
void display(int [],int,int);
void peek(int [],int,int);
int main()
{
	int f=-1,r=-1,ch,q[max];
	do{
		printf("enter\n1.enqueue\n2.dequeue\n3.display\n4.peek");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				r=enq(q,r);
				if(f==-1)
					f=0;
				break;
			case 2:
				f=deq(q,f,r);
				if(f==-1)
					r=-1;
				break;
			case 3:
				display(q,f,r);
				break;
			case 4:
				peek(q,f,r);
				break;
		}
	}while(ch<=4);
}
int enq(int q[],int r)
{
	int x;
	if(r==max-1)
	{
		printf("queue overflow");
	}
	else{
		printf("enter a number to enqueue");
		scanf("%d",&x);
		r++;
		q[r]=x;
	}
	return r;
}
int deq(int q[],int f,int r)
{	
	int x;
	if(f==-1 &&r==-1)
	{
		printf("queue empty");
	}
	else{
		x=q[f];
		printf("number dequeued is : %d",x);
		if(f==r)
			f=-1;
		else
			f++;
	}
	return f;
}
void display(int q[],int f,int r)
{
	if(f==-1 &&r==-1)
		printf("queue empty");
	else{
		while(f<=r)
		{
			printf("%d ",q[f]);
			f++;
		}
	}
}
void peek(int q[],int f,int r)
{
	if(f==-1 &&r==-1)
		printf("queue empty");
	else
		printf("peek element is : %d",q[f]);
}
