#include<stdio.h>
#define max 100

int safe_seq(int n,int m,int need[][m],int all[][m],int avail[],int finish[])
{   
    int work[m],safe[n],i,j,k=0,flag=1;
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    while(flag==1)
    {
       flag=0;
       for(i=0;i<n;i++)
       {
            if(finish[i]==1)
            {   
                continue;
            }
            else
            {   
                int t=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]-work[j]>0)
                    {   
                        t=1;
                        break;
                    }
                }
                if(t==1)
                {   
                    continue;
                }
                else
                {   
                    for(j=0;j<m;j++)
                    {
                        work[j]=work[j]+all[i][j];
                    }
                    finish[i]=1;
                    for(j=0;j<n;j++)
                    {
                        if(!finish[j])
                        {
                            flag=1;
                        }
                    }
                    safe[k]=i;
                    if(k!=n-1)
                    {
                        k++;
                    }   
                }
                
            }
        } 
    }
    if(k==n-1)
    {
        printf("safe sequence :\n");
        for(i=0;i<n;i++)
        {
            printf("%d\n",safe[i]);
        }
        return 1;
    }
    else
    {
        printf("safe sequence does not exist\n");
    }
    return 0;
}

int main()
{
    int n,m,i,j;
    printf("enter no of processes\n");
    scanf("%d",&n);
    printf("enter no of resource types\n");
    scanf("%d",&m);
    char ch;
    int avail[m],Max[n][m],all[n][m],need[n][m],finish[n],reqno,req[m],ret_val;
    for(i=0;i<m;i++)
    {
        printf("enter instances for resource type %d\n",i+1);
        scanf("%d",&avail[i]);
    }
    for(i=0;i<n;i++)
    {   
        printf("enter max instances required for process %d of\n",i);
        for(j=0;j<m;j++)
        {
            printf("resource type %d\n",j+1);
            scanf("%d",&Max[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {   
        printf("current no of instances allocated for process %d of\n",i);
        for(j=0;j<m;j++)
        {
            printf("resource type %d\n",j+1);
            scanf("%d",&all[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {   
        for(j=0;j<m;j++)
        {
            need[i][j]=Max[i][j]-all[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    //safe_seq(n,m,need,all,avail,finish); SAFE POINT
    //ret_val=safe_seq(n,m,need,all,avail,finish);
    /*do
    {
        printf("enter process no for request\n");
        scanf("%d",&reqno); 
        printf("enter request\n");
        for(i=0;i<m;i++)
        {
            scanf("%d",&req[i]);
        }
        int t=0;
        for(j=0;j<m;j++)
        {
            if(req[j]-need[reqno][j]>0)
            {   
                t=1;
                break;
            }
        }
        if(!t)
        {   
            int temp=0;
            for(j=0;j<m;j++)
            {   
                if(req[j]-avail[j]>0)
                {
                    temp=1;
                    break;
                }
            }
            if(!temp)
            {
                ret_val=safe_seq(n,m,need,all,avail,finish);
                printf("ret_val = %d\n",ret_val);
                if(ret_val)
                {
                    for(j=0;j<m;j++)
                    {
                        avail[j]=avail[j]-req[j];
                        all[reqno][j]=all[reqno][j]+req[j];
                        need[reqno][j]=need[reqno][j]-req[j];
                    }
                }
                else
                {
                    printf("process %d must wait as system is unsafe\n",reqno);
                }
                
            }
            else
            {
                printf("process %d must wait as resources are not available\n",reqno);
            }
        }
        else
        {
            printf("process %d has exceeded its maximum claim\n",reqno);
        }
        printf("do u want to contine ?\n");
        ch=getchar();
    } while(ch == 'y');*/
    ch = 'y';
    while(ch=='y')
    {
        printf("enter process no for request \n");
        scanf("%d",&reqno);
        printf("enter request\n");
        int temp=0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&req[i]);
            if(req[i]-need[reqno][i]>0)
            {
                temp=1;
                printf("process %d has exceeded max claim\n",reqno);
                break;
            }
        }
        if(temp!=1)
        {   
            int t;
            for(i=0;i<m;i++)
            {
                if(req[i]-avail[i]>0)
                {
                    t=1;
                    printf("process %d must wait since resources are not available\n",reqno);
                    break;
                }
            }
            if(t!=1)
            {
                ret_val=safe_seq(n,m,need,all,avail,finish);
                if(ret_val==1)
                {   
                    printf("request granted !\n");
                    for(i=0;i<m;i++)
                    {
                        avail[i]=avail[i]-req[i];
                        all[reqno][i]=all[reqno][i]+req[i];
                        need[reqno][i]=need[reqno][i]-req[i];
                    }
                }
                else
                {
                    printf("process %d must wait as system is unsafe\n",reqno);
                }
            }
        }
        printf("do u want to continue ?\n");
        scanf(" %c",&ch);
    }    
    return 0;
}
