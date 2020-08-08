#include<iostream>
using namespace std;
int main()
{
    int n; //no of vertices
    cout<<"enter no of vertices"<<endl;
    cin>>n;
    int c[n][n],i,j,k; // c is cost matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<"enter cost from "<<i<<" to "<<j<<endl;
            cin>>c[i][j];
        }
    }
    int d[n],start; //d is distance array, start is starting vertex 
    cout<<"enter starting vertex"<<endl;
    cin>>start;
    d[start] = 0;
    for(i=0;i<n;i++)
    {
        if(i==start)
        {
            continue;
        }
        else
        {
            d[i] = 100; //unreachable distance in this case
        }
    }
    int temp;
    for(k=0;k<n-1;k++)
    {   
        temp = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(c[i][j]!=100 && c[i][j]!=0)
                {
                    if(d[i]+c[i][j]<d[j])
                    {
                        d[j] = d[i]+c[i][j];
                        temp = 1;
                    }
                }
            }
        }
        if(temp==0)
        {
            break;
        }
    }
    cout<<"shortest routes from "<<start<<" are :"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<start<<" to "<<i<<" = "<<d[i]<<endl;
    }
    return 0;
}