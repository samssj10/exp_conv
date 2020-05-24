#include<iostream>
#define max 100
using namespace std;

class graph
{
    int n;//no of vertices
    int cost[max][max];
    public:
        graph()
        {
            cout<<"enter no of vertices"<<endl;
            cin>>n;
        }
        void adj_mat()
        {
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    cout<<"enter weight of edge from "<<i<<" to "<<j<<endl; //self loop = 0 , no edge = 100
                    cin>>cost[i][j];
                }
            }
        }

        int min_vertex(int wt[],bool visit[])
        {
            int i;
            int min_vertex=-1;
            for(i=0;i<n;i++)
            {
                if(!visit[i] && (min_vertex==-1 || wt[i]<wt[min_vertex]))
                {
                    min_vertex=i;
                }
            }
            return min_vertex;
        }

        void prims()
        {
            int start,curr,near[n],wt[n],i,j;
            bool visit[n];
            cout<<"enter starting vertex"<<endl;
            cin>>start;
            for(i=0;i<n;i++)
            {
                if(i==start)
                {
                    near[start]=-1;
                    visit[i]=1;
                    wt[i]=0;
                }
                else
                {
                    near[i]=start;
                    visit[i]=0;
                    wt[i]=max;
                }
            }
            curr = start;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(!visit[j])
                    {
                        if(cost[curr][j]<wt[j])
                        {
                            wt[j]=cost[curr][j];
                            near[j]=curr;
                        }
                    }
                }
                curr=min_vertex(wt,visit);
                visit[curr]=1;
                if(curr==-1)
                {
                    break;
                }
                else
                {
                    if(curr<near[curr])
                    {
                        cout<<curr<<" "<<near[curr]<<" "<<wt[curr]<<endl;
                    }
                    else
                    {
                        cout<<near[curr]<<" "<<curr<<" "<<wt[curr]<<endl;
                    }
                }
            }
        }
};

int main()
{
    graph g1;
    g1.adj_mat();
    g1.prims();
    return 0;
}
