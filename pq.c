#include<stdio.h>
#define max 6
int enq(int pq[],int r);
int main()
{
	int r=0,ch,pq[max];
	do{
		printf("\n1.enque  2.deque\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				r=enq(pq,r);
				break;
			}
			case2:
			{
				break;
			}
		}
	}while(ch<=2);
}

int enq(int pq[],int r)
{
	int data,prio;
	if(r==max-1)
	{
		printf("queue overflow");
	}
	else{
		printf("enter priority and data");
		scanf("%d%d",&prio,&data);
		pq[r]=prio;
		pq[r+1]=data;
		r+=2;
	}
	return r;
}
int deq(int pq[],int r)
{
	int  minp=pq[0],min,i;
	for(i=0;i<r;i++)
	{
		if(i%2==0)
		{
			if(pq[i]<minp)
			{
				minp=pq[i];
				min=pq[i+1];
				pq[i]=999;
			}
		}
	}
	printf("\nthe number dequeued is %d having priority %d\n",min,minp);
}
	
void display(int pq[],int r)
{
	for(i=0;i<r;i=i+2)
	{
		min=pq[i];
		for(j=0;j<r;j=j+2)
		{
			if(min>pq[j])
			{
				min=pq[j];
				pq[
			}
		}
		
				
		 	
	
	
		
