#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node 
{
    int coeff;
    int exp;
    struct node *next;
};

void create(struct node *head)
{
    struct node *temp; // for having a previous node reference
    temp=head;
    int i,n;
    printf("enter no of terms in the polynomial\n");
    scanf("%d",&n);
    printf("enter the terms in decreasing order of exponent\n");
    for(i=0;i<n;i++)
    {
        struct node *curr;
        curr=(struct node *)malloc(sizeof(struct node));
        printf("enter exponent and coefficient\n");
        scanf("%d",&curr->exp);
        scanf("%d",&curr->coeff);
        temp->next=curr;
        curr->next=head;
        temp=curr;
    }
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    if(temp->next==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        temp=temp->next;
        while(temp!=head)
        {   
            if(temp->next!=head)
            {
                printf("%dx^%d + ",temp->coeff,temp->exp);
            }
            else
            {
                printf("%dx^%d ",temp->coeff,temp->exp);
            }
                
            temp=temp->next;
        }
        printf("\n");
    }
}

void add(struct node *head1,struct node *head2)
{
    struct node *head3;
    head3=(struct node *)malloc(sizeof(struct node));
    head3->exp=-1;
    head3->next=head3;
    struct node *temp,*t1,*t2;
    temp=head3;
    t1=head1->next;
    t2=head2->next;
    while(t1->exp!=-1 && t2->exp!=-1)
    {
        if(t1->exp==t2->exp)
        {
            struct node *nterm;
            nterm=(struct node *)malloc(sizeof(struct node));
            nterm->exp=t1->exp;
            nterm->coeff=(t1->coeff)+(t2->coeff);
            nterm->next=head3;
            temp->next=nterm;
            temp=nterm;
            t1=t1->next;
            t2=t2->next;
        }
        if(t1->exp>t2->exp)
        {
            struct node *nterm;
            nterm=(struct node *)malloc(sizeof(struct node));
            nterm->exp=t1->exp;
            nterm->coeff=t1->coeff;
            nterm->next=head3;
            temp->next=nterm;
            temp=nterm;
            t1=t1->next;
        }
        if(t2->exp>t1->exp)
        {
            struct node *nterm;
            nterm=(struct node *)malloc(sizeof(struct node));
            nterm->exp=t2->exp;
            nterm->coeff=t2->coeff;
            nterm->next=head3;
            temp->next=nterm;
            temp=nterm;
            t2=t2->next;
        }
    }
    if(t2->exp!=-1)
    {
        temp->next=t2;
    }
    if(t1->exp!=-1)
    {
        temp->next=t1;
    }
    printf("sum of the 2 polynomials is :\n");
    display(head3);
}

void eval(struct node *head,int x)
{
    struct node *temp;
    temp=head->next;
    int result=0;
    while(temp!=head)
    {   
        int b=1;
        while(temp->exp!= 0)
        {
            b=b*x;
            --temp->exp;
        }
        result=result+(temp->coeff)*b;
        temp=temp->next;
    }
    printf("polynomial at x=%d is %d\n",x,result);
}

int main()
{
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->exp=-1;
    head->next=head;
    create(head);
    display(head);
    struct node *head2;
    head2=(struct node *)malloc(sizeof(struct node));
    head2->exp=-1;
    head2->next=head2;
    create(head2);
    display(head2);
    add(head,head2);
    int x;
    printf("enter value of x\n");
    scanf("%d",&x);
    eval(head,x);
}
