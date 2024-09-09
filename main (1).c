#include<stdio.h>
#include<stdlib.h>
typedef struct poly{
    int expo,coef;
    struct poly *next;
}poly;

poly *create();
poly * addpoly(poly*,poly*);
void display(poly *);



poly * create()
{
    poly *head=NULL,*newnode=NULL,*temp=NULL;
    int c,e;
    newnode=(poly * )malloc(sizeof(poly));
    if(newnode!=NULL)
    {
        printf("enter coef and expo");
        scanf("%d%d",&c,&e);
        newnode->coef=c;
        newnode->expo=e;
        newnode->next=NULL;
        if(head==NULL && temp==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=NULL;
        return head;
    }
}

poly * addpoly(poly *p1,poly* p2)
{
    poly *p=NULL,*l=NULL,*r=NULL;
    int e,c;
    //p1=3x^6 +4x^5 + 3x
    //p2=5x^6 +2x^5 + 2x^2x
    //so p2 last coef ka expo greater than 
    while(p1!=NULL&&p2!=NULL)
    {
        p=(poly*)malloc(sizeof(poly));
        if(p1->expo==p2->expo)
        {
            p->expo=p1->expo;
            p->coef=p1->coef+p2->coef;
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expo>p2->expo)
        {
            p->expo=p1->expo;
            p->coef=p1->coef;
            p1=p1->next;
        }
        else{
            p->expo=p2->expo;
            p->coef=p2->coef;
            p2=p2->next;
        }
        
        if(l==NULL && r==NULL)
        {
            l=r=p;
        }
        else{
            r->next=p;
            r=p;
            r->next=NULL;
        }
    }
    while(p1!=NULL)
    {
        p=(poly*)malloc(sizeof(poly));
        p->expo=p1->expo;
        p->coef=p1->coef;
        r->next=p;
        r=p;
        r->next=NULL;
    }
    while(p2!=NULL)
    {
        p=(poly*)malloc(sizeof(poly));
        p->expo=p1->expo;
        p->coef=p1->coef;
        r->next=p;
        r=p;
        r->next=NULL;
    }
    return l;           //l having address of frist node of third poly
}

void display(poly *p)
{
    while(p!=NULL)
    {
        printf("%dx^%d ",p->coef,p->expo);
        p=p->next;
    }
}
int main()
{
    poly *p1=NULL,*p2=NULL,*p3=NULL;
    p1=create();
    p2=create();
    p3=addpoly(p1,p2);
    display(p3);
}


