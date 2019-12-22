#include<stdio.h>
# define max 10  //max orders at one point of time
int front=-1;
int rear=-1;//linear queue
int frontcq=0;
int rearcq=0;//circular queue

int q[max];
int cq[max];
//cq[0]=0;
 
int isfull()
{
    if(rear==max-1)
    {
        printf("sorry we can't accept any more orders right now\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(front==rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int elem)
{
    if(!isfull())
    {
        rear++;
        q[rear]=elem;
        printf("your order has been taken\n");
        printf("rear = %d",rear);
    }
}

void dequeue()
{   
    if(!isempty())
    {   
        front++;
    }
}

void addcq(int elem)
{   
    int check=(rearcq+1)%max;
    printf("check=%d",check);
    if(check==front)
    {
        printf("sorry we can't accept any more orders right now\n");
    }
    else
    {
        rearcq=(rearcq+1)%max;
        cq[rearcq]=elem;
    }
}

void delcq()
{
    if(frontcq==rearcq)
    {
        printf("no orders left !\n");
    }
    else
    {
        frontcq=(frontcq+1)%max;
    }
    
}
