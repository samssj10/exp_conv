#include<stdio.h>
int calP1(int a[12])
{
    int i;
    int sum=0;
    for(i=2;i<12;i+2)
    {
        sum=sum+a[i];
    }
    if(sum%2==0)
    {
        a[0]=0;
        return a[0];
    }
    else
    {
        a[0]=1;
        return a[0];
    }
}

int calP2(int a[12])
{
    int i;
    int sum=0;
    sum=sum+a[2];
    for(i=5;i<12;i+4)
    {
        sum=sum+a[i]+a[i+1];
    }
    if(sum%2==0)
    {
        a[1]=0;
        return a[1];
    }
    else
    {
        a[1]=1;
        return a[1];
    }
}

int calP4(int a[12])
{
    int i;
    int sum=0;
    sum=sum+a[4]+a[5]+a[6]+a[11];
    if(sum%2==0)
    {
        a[3]=0;
        return a[3];
    }
    else
    {
        a[3]=1;
        return a[3];
    }
}

int calP8(int a[12])
{
    int i;
    int sum=0;
    for(i=8;i<12;i++)
    {
        sum=sum+a[i];
    }
    if(sum%2==0)
    {
        a[7]=0;
        return a[7];
    }
    else
    {
        a[7]=1;
        return a[7];
    }
}

/*int checkP1(int a[12])
{
    int i;
    int sum=0;
    for(i=2;i<12;i+2)
    {
        sum=sum+a[i];
    }
}*/

int main()
{
    int a[12];
    int i;
    printf("enter input\n");
    for(i=0;i<12;i++)
    {
        printf("here");
      if(i==0 || i==1 || i==3 || i==7)
      {
        continue;
      }
        printf("enter d%d",i);
        scanf("%d",&a[i]);
    }
    printf("frame received is :");
    for(i=0;i<12;i++)
    {
        printf("%d",a[i]);
    }
    int P1=calP1(a);
    int P2=calP2(a);
    int P4=calP4(a);
    int P8=calP8(a);
    printf("calculated values from received input : %d %d %d %d",P1,P2,P4,P8);

    return 0;
}   