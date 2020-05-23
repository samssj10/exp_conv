#include<stdio.h>
#define max 100

void safe_seq(int n,int m,int need[][m],int all[][m],int avail[],int finish[])
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
        return 0;
    }
    
}

int main()
{
    int n,m,i,j;
    printf("enter no of processes\n");
    scanf("%d",&n);
    printf("enter no of resource types\n");
    scanf("%d",&m);
    int avail[m],Max[n][m],all[n][m],need[n][m],finish[n],reqno,req[m],ret_val;
    char ch;
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
    safe_seq(n,m,need,all,avail,finish);
    return 0;
}
