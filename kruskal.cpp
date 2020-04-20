#include<iostream>
#define max 100
using namespace std;

class edge
{
    int v1;
    int v2;
    int cost;
    friend class graph;
};

class graph
{   
    int n,m;
    edge *e[max];
    public:

    graph()
    {
        cout<<"enter no of vertices"<<endl;
        cin>>n;
        cout<<"enter no of edges"<<endl;
        cin>>m;
    }
    
    int find_par(int v,int parent[])
    {
        if(parent[v]==v)
        {
            return v;
        }
        else
        {
            return find_par(parent[v],parent);
        }
        
    }

    void add_edge()
    {   
        int i;
        for(i=0;i<m;i++)
        {
            e[i]=new edge();
            cout<<"enter adj vertex 1 , adj vertex 2, enter cost "<<endl;
            cin>>e[i]->v1;
            cin>>e[i]->v2;
            cin>>e[i]->cost;
        }
        cout<<"added edges contain the costs :"<<endl;
        for(i=0;i<m;i++)
        {
            cout<<e[i]->cost<<endl;
        }
    }

    void sort_edges() //insertion sort
    {
        int i,j;
        for(i=1;i<m;i++)
        {
            edge *key;
            key=e[i];
            j=i-1;
            while(j>=0 && e[j]->cost>key->cost)
            {
                e[j+1]=e[j];
                j=j-1;
            }
            e[j+1]=key;
        }
        cout<<"sorted edges contain the costs :"<<endl;
        for(i=0;i<m;i++)
        {
            cout<<e[i]->cost<<endl;
        }
    }

    void kruskal()
    {
        edge *out[n-1]; //output edges
        int parent[n];   //parent array
        int i,cnt;
        for(i=0;i<n;i++)  //initialize parent array
        {   
            parent[i]=i;
        }
        i=0;
        cnt=0;
        while(cnt!=n-1)
        {
            edge *curr;
            curr=e[i]; //current edge taken from the input array
            
            //check whether added edge forms cycle
            char src_par,dest_par;
            src_par=find_par(e[i]->v1,parent);
            dest_par=find_par(e[i]->v2,parent);
            if(src_par!=dest_par)
            {   
                out[cnt]=new edge();
                out[cnt]=e[i];
                cnt++;
                parent[src_par]=dest_par; //can be done vice versa as well
            }
            i++;
        }
        
        cout<<"MST from the given input is : "<<endl;
        for(i=0;i<n-1;i++)
        {
            cout<<out[i]->v1<<" "<<out[i]->v2<<" "<<out[i]->cost<<endl;
        }
        
    }
};

int main()
{
    graph g1;
    g1.add_edge();
    g1.sort_edges();
    g1.kruskal();
    return 0;
}
