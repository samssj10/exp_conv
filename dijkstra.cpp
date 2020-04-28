#include<iostream>
#define max 100
using namespace std;

class graph
{
    int n; //vertices
    int e; //edges
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
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                   adj[i][j]=0; //initial value 0 showing no edge b/w i and j
                }
            }
            cout<<"enter weights in this form i -> j :"<<endl;
            //entering all wts of given edges
            for(i=0;i<e;i++)
            {
                int s,l,wt;
                cout<<"enter i , j , weight"<<endl;
                cin>>s>>l>>wt;
                adj[s][l]=wt;
            }
        }

        int find_min(int dist[max],bool visit[max])
        {
            int min_vertex=-1,i;
            for(i=0;i<n;i++)
            {
                if(!visit[i] && (min_vertex==-1 || dist[i]<dist[min_vertex]))
                {
                    min_vertex = i;
                }
            }
            return min_vertex;
        }

        void dijkstra()
        {
            bool visit[n]; //visited array
            int dist[n];  //distance from source array
            int i,j,start;  
            for(i=0;i<n;i++)
            {
                visit[i]=0;
                dist[i]=max;
            }
            cout<<"enter starting vertex"<<endl;
            cin>>start;
            dist[start]=0; //initialisation of source
            for(i=0;i<n;i++)
            {
                int min_vertex = find_min(dist,visit);
                visit[min_vertex]=1;
                for(j=0;j<n;j++)
                {
                    if(adj[min_vertex][j]!=0 && !visit[j])
                    {
                        int curr_dist = dist[min_vertex] + adj[min_vertex][j];
                        if(curr_dist < dist[j])
                        {
                            dist[j]=curr_dist;
                        }
                    }
                }
            }
            cout<<"starting with "<<start<<" min cost path to : "<<endl;
            for(i=0;i<n;i++)
            {
                cout<<i<<" = "<<dist[i]<<endl;
            }
        }
};

int main()
{
    graph g1;
    g1.adj_mat();
    g1.dijkstra();
    return 0;
}