#include<iostream>

int main()
{//for m=3
    int d[4];//4 bit dataword (k=4)
    printf("enter 4 bit dataword\n");
    int i;
    for(i=0;i<4;i++)
    {
        scanf("%d",&d[i]);
    }
    int r0,r1,r2;
    r0=d[2]^d[1]^d[0];
    r1=d[3]^d[2]^d[1];
    r2=d[1]^d[0]^d[3];
    int c[7]; //7 bit codeword (n=7) so 3 redundant bits
    int j=0;//for traversing dataword;
    for(i=3;i>=0;i--)
    {
        c[i]=d[j];
        j++;
    }
    c[4]=r2;
    c[5]=r1;
    c[6]=r0;
    int a[7];//user inputted codeword
    printf("enter 7 bit codeword\n");
    for(i=0;i<7;i++)
    {
        scanf("%d",&a[i]);
    }
    int s0,s1,s2;
    s0=a[2]^a[1]^a[0]^r0;
    s1=a[3]^a[2]^a[1]^r1;
    s2=a[1]^a[0]^a[3]^r2;
    int b=4*s2+2*s1+s0;

    if(b==3)
    {
        printf("bit a2 is wrong\n");
        a[5]=!a[5];
        printf("corrected codeword is :\n");
        for(i=6;i>=0;i--)
        {
            printf("%d",a[i]);
        }
    }
    if(b==5)
    {
        printf("bit a0 is wrong\n");
        a[3]=!a[3];
        printf("corrected codeword is :\n");
        for(i=6;i>=0;i--)
        {
            printf("%d",a[i]);
        }
    }
    if(b==7)
    {
        printf("bit a1 is wrong");
        a[0]=!a[0];
        printf("corrected codeword is :\n");
        for(i=6;i>=0;i--)
        {
            printf("%d",a[i]);
        }
    }
    if (b==0 || b==1 || b==2 || b==4 || b==6 )
    {
        printf("dataword received is correct\n");
    }
    
}
