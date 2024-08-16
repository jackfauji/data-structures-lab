#include<stdio.h>
#define max 10
int enq(int pq[],int r);
void deq(int pq[],int r);
void display(int pq[],int r);
int main()
{
	int pq[max],ch,r=0;
	do{
		printf("\nenter choice\n");
		printf("\n1.enque    2.deque   3.display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				r=enq(pq,r);
				break;
			}
			case 2:
			{
				deq(pq,r);
				break;
			}
			case 3:
			{
				display(pq,r);
				break;
			}
		}
	}while(ch<=3);
				
	}
	
int enq(int pq[],int r)
{
	int p,data;
	if(r>=max)
	{
		printf("overflow");
	}
	else{
		printf("enter priority and data");
		scanf("%d%d",&p,&data);
		pq[r]=p;
		pq[r+1]=data;
		r=r+2;
		}
	return r;
}
void deq(int pq[],int r)
{
	int i,j,min;
	if(r==0)
	{
		printf("\nunderflow\n");
	}
	else{
		for(i=2;i<r-1;i+=2)
		{
			min=pq[0];
			if(min>pq[i])
			{
				min=pq[i];
				j=i;
			}
		}
		printf("\n priority  %d  data has be poped that is : %d\n",min,pq[j+1]);
		pq[j]=999;
	}
}
void display(int pq[],int r)
{
	int min,i,j,x;
	for(i=0;i<r-1;i+=2)
	{
		min=pq[i];
		for(j=0;j<r-1;j+=2)
		{
			if(pq[i]!=999 && pq[j]!=999)
			{
				if(min>pq[j])
				{
					min=pq[j];
					x=j;
					pq[j]=999;
				}
			}
		}
		if(min!=999)
		printf("\n %d : %d\n",min,pq[x+1]);
	}
}	
