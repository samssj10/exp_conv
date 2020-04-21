#include<iostream>
#define max 100
using namespace std;

class graph
{
    int n; //no of vertices
    int e; //no of edges
    int adj[max][max];
    public:
        graph()
        {
            cout<<"enter no of vertices"<<endl;
            cin>>n;
            cout<<"enter no of edges"<<endl;
            cin>>e;
        }

        void adj_mat()
        {
            cout<<"enter weights for :"<<endl;
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                   adj[i][j]=0; //initial value
                }
            }

            //entering all wts of given edges
            for(i=0;i<e;i++)
            {
                int s,l,wt;
                cout<<"enter smaller vertex , larger vertex , weight"<<endl;
                cin>>s>>l>>wt;
                adj[s][l]=wt;
            }
        }

        int find_min(int wt[max],bool visit[max],int n)
        {
            int min_vertex=-1;
            int i;
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
            int par[n],wt[n],start,i,j;
            bool visit[n];
            for(i=0;i<n;i++)
            {
                wt[i]=max;
                visit[i]=0;
            }
            cout<<"enter starting vertex"<<endl;
            cin>>start;
            wt[start]=0;
            par[start]=-1;
            for(i=0;i<n;i++)
            {
                int min_vertex=find_min(wt,visit,n);
                visit[min_vertex]=1;
                for(j=0;j<n;j++)
                {
                    if(adj[min_vertex][j]!=0 && !visit[j])
                    {
                        if(adj[min_vertex][j]<wt[j])
                        {
                            wt[j]=adj[min_vertex][j];
                            par[j]=min_vertex;
                        }
                    }
                }
            }
            for(i=1;i<n;i++)
            {
                if(par[i]<i)
                {
                    cout<<par[i]<<" "<<i<<" "<<wt[i]<<endl;
                }
                else
                {
                    cout<<i<<" "<<par[i]<<" "<<wt[i]<<endl;
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