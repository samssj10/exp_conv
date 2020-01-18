#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
};

struct node *getnode()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}

void create(struct node *head)
{
    struct node *temp,*curr;
    temp=head;
    int i,n;
    printf("enter no of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   
        curr=getnode();
        temp->next=curr;
        curr->prev=temp;
        temp=curr;
    }
}

void display(struct node *head)
{
    struct node *temp;
    temp=head->next;
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        printf("%u \t",temp->prev);
        printf("%u \t",temp);
        printf("%u \n",temp->next);
        temp=temp->next;
    }
}

int length(struct node *head)
{
    struct node *temp;
    temp=head->next;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}

void insert(struct node *head)
{
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
    curr=head->next;
    int len=length(head);
    int i,pos;
    i=1;
    printf("enter position to insert\n");
    scanf("%d",&pos);
    if(pos>len+1)
    {
        printf("node cannot be inserted\n");
    }
    else
    {
        while(curr!=NULL && i<pos)
        {
            i++;
            curr=curr->next;
        }
        struct node *nnode;
        nnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&nnode->data);
        nnode->next=curr->next;
        nnode->prev=curr;
        if(pos!=len) // cannot be done if node is inserted at last position
        {
        curr->next->prev=nnode;
        }
        curr->next=nnode;
    }
    
}

void delete(struct node *head)
{
    struct node *curr,*oldnode;
    curr=head->next;
    int len=length(head);
    int i=1;
    int pos;
    printf("enter pos of node to delete\n");
    scanf("%d",&pos);
    if(pos>len)
    {
        printf("node cant be deleted\n");
    }
    else if(pos==1)
    {
        head->next=curr->next;
        curr->next->prev=head;
        free(curr);
    }
    else
    {   
        while(curr!=NULL && i<pos)
        {   
            if(i==pos-1)
            {
                oldnode=curr->next;
                curr->next=oldnode->next;
                if(pos!=len)
                {
                    oldnode->next->prev=curr;
                }
                free(oldnode);
            }
            curr=curr->next;
            i++;
        }

    }
    
}

int main()
{
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    create(head);
    display(head);
    insert(head);
    display(head);
    delete(head);
    display(head);
    return 0;
}