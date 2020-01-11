#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next; //to create links between the nodes we need pointer with the data type of node
};

struct node *getnode()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->next=NULL; //cannot be written without allocating memory
    return temp;
}

struct node *create()
{
    struct node *temp;
    struct node *first;
    first=NULL;
    struct node *last;
    last=NULL;
    int i,n;
    printf("enter no of nodes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=getnode();
        if(first==NULL)
        {
            first=temp;
            last=temp;
        }
        else
        {
            last->next=temp;
            last=temp;
        }
        
    }
    return first;
}

int length(struct node *head)
{
    int n=0;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp=head->next; //temp pointing to first node
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    printf("current length of linked list is %d\n",n);
    return n;

}

/*void insert(struct node *head)
{   
    struct node *nnode;// nth node to be inserted
    nnode=(struct node *)malloc(sizeof(struct node));
    int val;
    printf("enter value\n");
    scanf("%d",&val);
    nnode->data=val;
    nnode->next=

}*/

void insert(struct node *head) //insert by position
{
    int i=1; //for pointing to first node
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
    curr=head->next;
    int pos;
    printf("enter position to insert the node\n");
    scanf("%d",&pos);
    int k=length(head);
    printf("length=%d\n",k);
    if(pos>k+1) // k+1 means same as kth position in terms of inserting a node
    {
        printf("data cannot be inserted\n");
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
        curr->next=nnode;
    }
    
}

void display(struct node *head)
{
    if(head->next==NULL)
    {
        printf("linked list is empty \n");
    }
    else
    {
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp=head->next;
        while(temp!=NULL) //saves writing one extra printf statement
        {
            printf("%d \t",temp->data);
            printf("%u \t",temp);
            printf("%u \n",temp->next);
            temp=temp->next;
        }
    }
    
}

int delete(struct node *head)
{
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
    struct node *prev;
    prev=(struct node *)malloc(sizeof(struct node));
    struct node *temp;
    prev=head;
    int ctr=1; //counter for tracking the nodes
    curr=prev->next; //basically first node
    int pos;
    printf("enter position of node to delete\n");
    scanf("%d",&pos);
    int len=length(head);
    if(pos>len)
    {
        printf("node cannot be deleted\n");
        return 0;
    }
    else if(pos==1)
    {
        head->next=curr->next;
        free(curr);
        return 1;
    }
    else
    {
        while(ctr<pos && curr!=NULL)
        {
            if(ctr==pos-1) //actually deletes the previous position
            {
                temp=curr;
                prev->next=curr->next;
                curr->next=NULL;
                free(temp);
                return 1;
            }
            prev=curr;
            curr=curr->next;
            ctr++;
        }
    }
}

struct node *reverse (struct node *head)
{
    struct node *first;
    struct node *prev;
    prev=NULL;
    struct node *mid;
    mid=(struct node *)malloc(sizeof(struct node));
    mid=head->next;
    struct node *ptr; 
    ptr=NULL;
    while(mid!=NULL)
    {
        ptr=mid->next; 
        prev=mid;
        mid=ptr;
        ptr=ptr->next;
        mid->next=prev;
    }
    first=mid;
    return first;
}

int main()
{   
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));// sizeof calculates size of struct node and then malloc allocates that much space in memory and returns it to head
    head->next=NULL;// linked list is empty at beginning.
    struct node *first;
    first=NULL;// pointer needs to initialized
    int delstat;
    int n;
    while(n!=8)
    {
        printf("enter your choice :\n1.create\n2.display\n3.insert a node\n4.delete a node\n5.reverse\n6.sort\n7.merge\n8.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                first=create();
                head->next=first;
                break;
            case 2:
                display(head);
                break;
            case 3://insert by position
                insert(head);
                break;
            case 4://delete by position
                delstat=delete(head);
                if(delstat==1)
                {
                    printf("node successfully deleted\n");
                }
                break;
            case 5:
                first=reverse(head);
                head->next=first;
                break;
                

        }
    }
    return 0;
}