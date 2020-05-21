#include<iostream>
#define max 100
using namespace std;

void insert(int a[max],int i)
{   
    int n=i,elem = a[i];
    while((i+1>1) && (a[((i+1)/2)-1]<elem))
    {
        a[i]=a[((i+1)/2)-1];
        i=((i+1)/2)-1;
    }
    a[i]=elem;
}

void adjust(int a[max],int n,int i)
{
    while(((2*i)+1)<n)
    {
       int j = (2*i)+1;
       if(((j+1)<n) && (a[j]<a[j+1]))
       {
            j=j+1;
       }    
       if(a[i]>=a[j])
       {
           break;
       }
       if(a[i]<a[j])
       {
          int temp;
          temp = a[i];
          a[i]=a[j];
          a[j]=temp;
          i=j; 
       }
    }
}

int main()
{
    int n,m;
    cout<<"enter no of students"<<endl;
    cin>>n;
    m=n;
    int a[n],i,temp;
    for(i=0;i<n;i++)
    {
        cout<<"enter marks for student "<<i+1<<endl;
        cin>>a[i];
        insert(a,i);
    }
    while(n>1)
    {
        temp=a[0];
        a[0]=a[n-1];
        a[n-1]=temp;
        n--; //reducing one index
        adjust(a,n,0);
    }
    cout<<"sorted heap looks like :"<<endl;
    for(i=0;i<m;i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}