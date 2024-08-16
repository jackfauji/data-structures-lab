//implementing double ended queue(input restricted)
#include<stdio.h>
#define max 5
int enq(int dq[],int r);
int deqf(int dq[],int f,int r);
int deqr(int dq[],int f,int r);
void display(int dq[],int f,int r);
int main()
{
	int dq[max],ch,r=-1,f=-1;
	do{
		printf("\nenter choice\n");
		printf("\n1.enque    2.deque from front   3.deque from rear\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				r=enq(dq,r);
				if(f==-1)
					f=0;
				break;
			}
			case 2:
			{
				f=deqf(dq,f,r);
				if(f==-1)
					r=-1;
				break;
			}
			case 3:
			{
				r=deqr(dq,f,r);
				if(r==-1)
					f=-1;
				break;
			}
			case 4:
			{
				display(dq,f,r);
				break;
			}
		}
	}while(ch<=4);
				
}
int enq(int dq[],int r)
{
	int x;
	if(r==max-1)
		printf("overflow");
	else{
		printf("\nenter no.to enqueue\n");
		scanf("%d",&x);
		r++;
		dq[r]=x;
	}
	return r;
}
int deqf(int dq[],int f,int r)
{
	int x;
	if(f==-1 && r==-1)
		printf("underflow");
	else{
		x=dq[f];
		printf("\nno dequeued is %d\n",x);
		if(f==r)
			f=-1;
		else
			f++;
	}
	return f;
}
int deqr(int dq[],int f,int r)
{
	int x;
	if(f==-1 && r==-1)
		printf("underflow");
	else{
		x=dq[r];
		printf("\nno.dequeued is : %d\n",x);
		if(f==r)
			r=-1;
		else
			r--;
	}
	return r;
}
void display(int dq[],int f,int r)
{
	if(f==-1 && r==-1)
		printf("underflow");
	else{
		while(f<=r)
		{
			printf("%d ",dq[f]);
			f++;
		}
	}
}
		
	
