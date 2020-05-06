#include<stdio.h>
# define max 100 

struct pro
{
    float at,bt,wt,tat,rem_t; 
};

void insertion_sort(struct pro *a,int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        struct pro key=a[i];
        j=i-1;

        while(j>=0 && a[j].at>key.at)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;//takes care of both cases ie, when all subelements are greater or when one is smaller
    }
}

void fcfs(struct pro *p,int n)
{   
    int i;
    float curr_time=p[0].at,tot_tat=0,tot_wt=0;
    for(i=0;i<n;i++)
    {
        curr_time=curr_time+p[i].bt;
        p[i].tat=curr_time-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        tot_tat=tot_tat+p[i].tat;
        tot_wt=tot_wt+p[i].wt;
        if(i<n-1 && curr_time<p[i+1].at)
        {
            curr_time=p[i+1].at;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("process %d wt = %f , tat = %f\n",i+1,p[i].wt,p[i].tat);
    }
    printf("average wt = %f\n",tot_wt/n);
    printf("average tat = %f\n",tot_tat/n);
}

void sjf(struct pro *p,int n)
{   
    float curr_time=p[0].at,tot_tat=0,tot_wt=0;
    int i,j,k=0,complete[n],flag;
    for(i=0;i<n;i++)
    {
        p[i].rem_t=p[i].bt;
        complete[i]=0;
    }
    while(k!=n)
    {   
        flag=0;
        int min_t=max;
        for(i=0;i<n;i++)
        {   
            if(!complete[i] && curr_time>=p[i].at && p[i].rem_t<min_t)
            {
                min_t=p[i].rem_t;
                j=i;
                flag=1;
            }
        }
        curr_time++;
        if(flag==0) //cpu should not be idle
        {   
            min_t=max;
            for(i=0;i<n;i++)
            {   
                if(curr_time<=p[i].at && p[i].at<min_t)
                {
                    min_t=p[i].at;
                    j=i;
                    flag=1;
                }
            }  
        }
        p[j].rem_t--;
        if(p[j].rem_t==0)
        {   
            k++;
            complete[j]=1;
            p[j].tat=curr_time-p[j].at;
            p[j].wt=p[j].tat-p[j].bt;
            tot_tat=tot_tat+p[j].tat;
            tot_wt=tot_wt+p[j].wt;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("process %d wt = %f , tat = %f\n",i+1,p[i].wt,p[i].tat);
    }
    printf("average wt = %f\n",tot_wt/n);
    printf("average tat = %f\n",tot_tat/n);
}

int main()
{   
    int n,i,ch=0;
    printf("enter no of processes\n");
    scanf("%d",&n);
    struct pro p[n];
    printf("enter arrival time and burst time for :\n");
    for(i=0;i<n;i++)
    {
        printf("process %d\n",i+1);
        scanf("%f",&p[i].at);
        scanf("%f",&p[i].bt);
    }
    insertion_sort(p,n);
    while(ch!=3)
    {
        printf("enter choice :\n1.first come first serve\n2.shortest job first (preemptive)\n3.exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            fcfs(p,n);
            break;
        case 2:
            sjf(p,n);
            break;
        }
    }
    return 0;
}
