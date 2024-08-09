#include<stdio.h>
#define max 10
int enq(int [],int,int);
int deq(int [],int ,int);
void display(int [],int,int);
void peek(int [],int,int);
int main()
{
	int f=-1,r=-1,ch,cq[max];
	do{
		printf("\nenter\n1.enqueue\n2.dequeue\n3.display\n4.peek\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				r=enq(cq,f,r);
				if(f==-1)
					f=0;
				break;
			case 2:
				f=deq(cq,f,r);
				if(f==-1)
					r=-1;
				break;
			case 3:
				display(cq,f,r);
				break;
			case 4:
				peek(cq,f,r);
				break;
		}
	}while(ch<=4);
}
int enq(int cq[],int f,int r)
{
	int x;
	if((r+1)%max==f)
		printf("overflow");
	else{
		printf("enter number");
		scanf("%d",&x);
		r=(r+1)%max;
		cq[r]=x;
	}
	return r;
}
int deq(int cq[],int f,int r)
{
	int x;
	if(f==-1 &&r==-1)
		printf("queue empty");
	else{
		x=cq[f];
		printf("dequeued element is : %d",x);
		if(f==r)
			f=-1;
		else
			f=(f+1)%max;
	}
	return f;
}
void display(int cq[],int f,int r)
{
	if(f==-1 &&r==-1)
		printf("empty");
	else{
		while(f!=r)
		{
			printf("%d ",cq[f]);
			f=(f+1)%max;
		}
		printf("%d ",cq[f]);
	}
}
void peek(int cq[],int f,int r)
{
	if(f==-1 &&r==-1)
		printf("queue empty");
	else
		printf("peek element is : %d",cq[f]);
}












