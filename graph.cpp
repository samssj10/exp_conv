#include<iostream>
#define max 100
using namespace std;

class node
{
    char data;
    node *next;
    friend class graph;
    friend class stack;
};

class stack
{
    int top;
    node *data[max];
    friend class graph;
    public:
        stack()
        {
            top=-1;
        }
        void push(node *temp)
        {
          if(top!=max-1)
          {
            top++;
            data[top]=temp;
          }  
        }
        node *pop()
        {
            node *temp;
            temp=data[top];
            top--;
            return temp;
        }

};

class graph  //adjacency list representation
{
    node *head[max];
    int n;
    stack st;
    public:
        graph()
        {
            cout<<"enter no of vertices"<<endl;
            cin>>n;
            int i;
            for(i=0;i<n;i++)
            {
                head[i]=new node();
                cout<<"enter vertex"<<endl;
                cin>>head[i]->data;
            }
        }

        void create()
        {
            int i;
            for(i=0;i<n;i++)
            {
                node *temp;
                temp=head[i];
                char new_data,ch;
                do
                {
                    cout<<"enter adjacent vertex for "<<head[i]->data<<endl;
                    cin>>new_data;
                    if(new_data==head[i]->data)
                    {
                        cout<<"self loops not allowed"<<endl;
                    }
                    else
                    {
                        node *nnode;
                        nnode=new node();
                        nnode->data=new_data;
                        temp->next=nnode;
                        temp=temp->next;
                    }
                    cout<<"do u wish to continue ?"<<endl;
                    cin>>ch;
                } while (ch=='y');
                temp->next=NULL;
            }
        }

        void display_rec()
        {
            int visit[n],i;
            for(i=0;i<n;i++)
            {
                visit[i]=0;
            }
            char start;
            cout<<"enter starting vertex"<<endl;
            cin>>start;
            cout<<"recursive display below :"<<endl;
            dfs(start,visit);
        }

        void dfs(char curr,int visit[])
        {
            cout<<curr<<endl;
            int i;
            for(i=0;i<n;i++)
            {
                if(head[i]->data==curr)
                {
                    visit[i]=1; //visited
                    break;
                }
            }
            node *temp;
            temp=head[i]->next;
            while(temp!=NULL)
            {   
                i=0;
                while(head[i]->data!=temp->data)
                {
                    i++;
                }
                if(visit[i]!=1)
                {
                    dfs(temp->data,visit);
                }
                temp=temp->next; //to reach every adjacent vertex of head node
            }
        }

        void display()
        {   
            node *temp,*curr;
            int visit[n],i,j;
            for(i=0;i<n;i++)
            {
                visit[i]=0;
            }
            char start;
            cout<<"enter starting vertex"<<endl;
            cin>>start;
            for(i=0;i<n;i++)
            {
                if(head[i]->data==start)
                {
                    visit[i]=1; //visited
                    temp=head[i];
                    st.push(temp);
                    break;
                }
            }
            temp=head[i];
            cout<<"non-rec display below :"<<endl;
            do
            {
                curr=st.pop();
                cout<<curr->data<<endl;
                while(temp!=NULL)
                {
                    temp=temp->next; //meant for traversing the starting vertext list only
                    curr=temp;
                    while(curr!=NULL)
                    {   
                        j=0;
                        while(head[j]->data!=curr->data)
                        {   
                            j++;
                        }
                        if(visit[j]!=1)
                        {
                            visit[j]=1; //visited
                            curr=head[j];
                            st.push(curr);
                        }
                        curr=curr->next;//meant for traversing each adjacent vertext list individually
                    }
                }
            } while (st.top!=-1);
            

            
        }
};

int main()
{
    graph g1;
    g1.create();
    g1.display_rec();
    g1.display();
    return 0;
}
