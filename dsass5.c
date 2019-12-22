#include<stdio.h>
#include "queue.h"
int main()
{
    printf("welcome to sams pizza !\n");
    int n=0;// order type
    int a=0;// to keep track of no of orders
    int s;// which type of queue is needed
    printf("which system do you want to use ?\n1.linear queue\n2.circular queue");
    scanf("%d",&s);
    switch(s)
    {
    case 1:    
        while(n!=4)
        {   
            printf("enter your choice 1.paneer pizza 2.chicken pizza 3.onion pizza 4.exit\n");
            scanf("%d",&n);   
            switch(n)
            {
                case 1:
                    enqueue(n);
                    a++;
                    printf("a=%d",a);
                    printf("front=%d",front);
                    break;
                case 2:
                    enqueue(n);
                    a++;
                    printf("a=%d",a);   
                    printf("front=%d",front);
                    break;
                case 3:
                    enqueue(n);
                    a++;
                    printf("a=%d",a);    
                    printf("front=%d",front);
                    break;
            }
        }
        break;
    case 2:
         while(n!=4)
        {   
            printf("enter your choice 1.paneer pizza 2.chicken pizza 3.onion pizza 4.exit\n");
            scanf("%d",&n);   
            switch(n)
            {
                case 1:
                    printf("rearcq=%d\n",rearcq);
                    printf("frontcq=%d\n",frontcq);
                    addcq(n);
                    printf("rearcq=%d\n",rearcq);
                    a++;
                    break;
                case 2:
                    addcq(n);
                    a++;
                    break;
                case 3:
                    addcq(n);
                    a++;
                    break;
            }
        }

    }
    if(s==1)
    {
        if(a>=10)
        {   
            int b=1;// for showing order id
            while(front!=rear)
            {   
                int m;
                printf("how many pizzas have you ordered\n");
                scanf("%d",&m);
                printf("front=%d",front);
                while(m!=0)
                {   
                    printf("finished preparing pizza type %d for order id abcd%d\n",q[front+1],b);
                    dequeue();
                    m--;
                }
                printf("please make your payment to get your pizza !\n");
                printf("thank you for the payment\nenjoy your pizza !\n");
                b++;
            }
            printf("no orders left !\n");
        }
    }
    else
    {
        if(a>=10)
        {   
            printf("frontcq=%d rearcq=%d",frontcq,rearcq);
            int b=1;// for showing order id
            while(frontcq!=rearcq)
            {   
                int m;
                printf("how many pizzas have you ordered\n");
                scanf("%d",&m);
                while(m!=0)
                {   
                    printf("finished preparing pizza type %d for order id abcd%d\n",cq[(frontcq+1)%max],b);
                    delcq();
                    m--;
                }
                printf("please make your payment to get your pizza !\n");
                printf("thank you for the payment\nenjoy your pizza !\n");
                b++;
            }
            printf("no orders left !\n");
        }
    }
    
    return 0;
}   