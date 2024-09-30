//ll ny inserting nodes in such a way that the  resultant linked list remians in ascending order(do not use any sorting algo)

#include<stdio.h>
#include<stdlib.h>
typedef struct dlist{
	struct dlist *prev;
	int data;
	struct dlist *next;
}dl;

dl * dinsert(dl*);
dl *ddel(dl*);
void display(dl *);

int main()
{
	dl *f=NULL,*r=NULL;
	int ch;
	do{
		printf("\nenter what is ur preference");
		printf("\n1.enque\n2.deque\n3.display");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				r=dinsert(r);
				if(f==NULL)
					f=r;
				break;
			case 2:
				f=ddel(f);
				if(f==NULL)
					r=NULL;
				break;
			case 3:
				display(f);
				break;
		}
	}while(ch<=3);
	
}

dl *dinsert(dl * r)
{
	dl *p=NULL;
	p=(dl*)malloc(sizeof(dl));
	if(p!=NULL)
	{
		printf("\nenter data");
		scanf("%d",&p->data);
		if(r==NULL)
		{
			r=p;
			p->prev=NULL;
		}
		else{
			r->next=p;
			p->prev=r;
			r=p;
		}
		r->next=NULL;
		return r;
	}
}

dl* ddel(dl *f)
{
	dl*p=NULL;
	if(f==NULL)
		printf("empty");
	else{
		p=f;
		printf("deleted data : %d",p->data);
		f=f->next;
		if(f!=NULL)
			f->prev=NULL;
		free(p);
		return f;
	}
}


void display(dl *f)
{
	dl *p=f;
	if(f==NULL)
		printf("empty");
	else{
		do{
			printf("%d ",p->data);
			p=p->next;
		}while(p!=NULL);
		printf("\n");
	}
}
		
