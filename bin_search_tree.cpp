#include<iostream>
#define max 100
using namespace std;

class node 
{
    int data;
    node *left,*right;
    friend class tree;
    friend class queue;
    friend class stack;
};

class stack
{
    int top;
    node *data[max];
    friend class tree;
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

class queue
{
    int front;
    int rear;
    node *data[max];
    friend class tree;
    public:
        queue()
        {
            front=-1;
            rear=-1;
        }
        void enqueue(node *temp)
        {
            if(rear!=max-1)
            {
                rear++;
                data[rear]=temp;
            }
        }
        node *dequeue()
        {
            if(front!=rear)
            {
                node *temp;
                front++;
                temp=data[front];
                return temp;
            }
        }
};

class tree
{
    node *root;
    queue q;
    stack s1,s2;    
    public:
        tree()
        {   
            root=new node();
            root->data=0;
            root->left=NULL;
            root->right=NULL;
        }

        void create_tree()
        {
            node *temp;
            cout<<"enter root value of your tree"<<endl;
            cin>>root->data;
            int n;//tells no of nodes
            cout<<"enter no of nodes"<<endl;
            cin>>n;
            int i;
            temp=root;
            for(i=1;i<=n;i++)
            { 
                create_rem(temp);
            }
        }

        void create_rem(node *temp)
        {
            node *nnode;
            nnode=new node();
            cout<<"enter data"<<endl;
            cin>>nnode->data;
            int flag=0;
            while(flag==0)
            {
                if(nnode->data<temp->data)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=nnode;
                        nnode->left=NULL;
                        nnode->right=NULL;
                        flag=1;
                    }
                    else
                    {
                        temp=temp->left;
                        nnode->left=NULL;
                        nnode->right=NULL;
                    }
                }
                else
                {
                    if(temp->right==NULL)
                    {
                        temp->right=nnode;
                        nnode->left=NULL;
                        nnode->right=NULL;
                        flag=1;
                    }
                    else
                    {
                        temp=temp->right;
                        nnode->left=NULL;
                        nnode->right=NULL;
                    }
                    
                }
                
            }
        
        }

        void create_tree_rec()
        {
            node *temp;
            cout<<"enter root value of your tree"<<endl;
            cin>>root->data;
            int n;//tells no of nodes
            cout<<"enter no of nodes"<<endl;
            cin>>n;
            int i;
            temp=root;
            int inp; //input data
            for(i=1;i<=n;i++)
            {   
                cout<<"enter data"<<endl;
                cin>>inp;
                create_rem_rec(temp,inp);
            }
        }

        void create_rem_rec(node *temp,int inp)
        {
            if(inp<temp->data)
            {
                if(temp->left==NULL)
                {
                    node *nnode;
                    nnode=new node();
                    nnode->data=inp;
                    nnode->left=NULL;
                    nnode->right=NULL;
                    temp->left=nnode;
                }
                else
                {
                    create_rem_rec(temp->left,inp);
                }
            }
            else
            {
                if(temp->right==NULL)
                {
                    node *nnode;
                    nnode=new node();
                    nnode->data=inp;
                    nnode->left=NULL;
                    nnode->right=NULL;
                    temp->right=nnode;
                }
                else
                {
                    create_rem_rec(temp->right,inp);
                }
            }
            
        }



        void display_dfs() //Binary Traversals
        {   
            int n;
            cout<<"how do u want to display:\n1.inorder(rec)\n2.preorder(rec)\n3.postorder(rec)\n"<<endl;
            cin>>n;
            switch(n)
            {
                case 1:
                    inorder_rec(root);
                    break;
                case 2:
                    preorder_rec(root);
                    break;
                case 3:
                    postorder_rec(root);
                    break;
            }
        }
        void inorder_rec(node *temp)
        {
            if(temp!=NULL)
            {
                inorder_rec(temp->left);
                cout<<temp->data<<endl;
                inorder_rec(temp->right);
            }
        }
        
        void preorder_rec(node *temp)
        {
            if(temp!=NULL)
            {
                cout<<temp->data<<endl;
                preorder_rec(temp->left);
                preorder_rec(temp->right);
            }
        }

        void postorder_rec(node *temp)
        {
            if(temp!=NULL)
            {
                postorder_rec(temp->left);
                postorder_rec(temp->right);
                cout<<temp->data<<endl;
            }
        }

        void mirror_create()
        {
            node *curr;
            curr=root;
            mirror_rec(curr);
        }
        void mirror_rec(node *curr)
        {
            if(curr->left!=NULL && curr->right!=NULL)
            {
                node *temp;
                temp=curr->left;
                curr->left=curr->right;
                curr->right=temp;
                mirror_rec(curr->left);
                mirror_rec(curr->right);
            }
            if(curr->left!=NULL && curr->right==NULL)
            {
                curr->right=curr->left;
                curr->left=NULL;
                mirror_rec(curr->right);
            }
            if(curr->left==NULL && curr->right!=NULL)
            {
                curr->left=curr->right;
                curr->right=NULL;
                mirror_rec(curr->left);
            }
        }

        void mirror()
        {
            node *temp;
            temp=root;
            q.enqueue(temp);
            while(q.front!=q.rear)
            {
                temp=q.dequeue();
                cout<<temp->data;
                node *temp2;
                temp2=temp->left;
                temp->left=temp->right;
                temp->right=temp2;
                if(temp->left!=NULL)
                {
                    q.enqueue(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.enqueue(temp->right);
                }
            }

        }

        void depth() //no of edes between node and root node
        {
            node *temp;
            temp=root;
            int n;//input no to find depth
            cout<<"enter value of node"<<endl;
            cin>>n;
            int edge=0;
            int flag = 0;
            //while(temp->data!=n && temp!=NULL)
            while(flag==0)
            {   
                if(temp!=NULL)
                {   
                    if(temp->data!=n)
                    {
                        if(n<temp->data)
                        {
                            temp=temp->left;
                            edge++;
                        }
                        else
                        {
                            temp=temp->right;
                            edge++;
                        }
                    }
                    else
                    {
                        flag=1;
                    }
                    
                }
                else
                {
                    flag=1;
                }
                
            }
            if(temp==NULL)
            {
                cout<<"invalid node entered"<<endl;
            }
            else
            {
                cout<<"depth of node "<<n<<" is "<<edge<<endl; //worls for both root node and any other node
            }
        }

        int maximum(int a,int b)
        {
            if(a>b)
            {
                return a;
            }
            else //works for both less and equal case
            {
                return b;
            }
        }

        void height() //no of edges between node and leaf node on the longest path possible
        {
            node *temp;
            temp=root;
            int n;//input no to find height
            cout<<"enter value of node"<<endl;
            cin>>n;
            while(temp->data!=n)
            {
                if(n<temp->data)
                {
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
            cout<<"height of node "<<n<<" is "<<node_ht(temp)-1<<endl;
        }

        int node_ht(node *temp)
        {
            if(temp==NULL) //leaf node condition
            {
                return 0;
            }
            else
            {
                return (maximum(node_ht(temp->left),node_ht(temp->right))+1);
            }
            
        }




        void level() //level = depth + 1
        {
            node *temp;
            temp=root;
            int n;//input no to find depth
            cout<<"enter value of node"<<endl;
            cin>>n;
            int edge=0;
            while(temp->data!=n)
            {   
                edge++;
                if(n<temp->data)
                {
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
            cout<<"level of node "<<n<<" is "<<edge+1<<endl;
        }
        void copy_tree_rec(tree t1) //use preordr approach
        {
            root=copy(t1.root);
            cout<<"copied tree is "<<endl;
        }
        
        node *copy(node *curr)
        {   
            node *temp;
            temp=NULL; //required for setting the base case in which it points to NULL
            if(curr!=NULL)
            {
                temp=new node();
                temp->data=curr->data;
                temp->left=copy(curr->left);
                temp->right=copy(curr->right);
            }
            return temp;
        }
        
        void copy_tree(tree t1)
        {
            node *temp1,*temp2;
            temp2=root;//copy tree
            temp1=t1.root;//original tree
            temp2->data=temp1->data;
            while(1)
            {
                while(temp1!=NULL)
                {
                    if(temp1->left!=NULL)
                    {
                        node *nnode=new node();
                        nnode->data=temp1->left->data;
                        nnode->left=NULL;
                        nnode->right=NULL;
                        temp2->left=nnode;
                        
                    }
                    if(temp1->right!=NULL)
                    {
                        node *nnode=new node();
                        nnode->data=temp1->right->data;
                        nnode->left=NULL;
                        nnode->right=NULL;
                        temp2->right=nnode;
                    }
                    s2.push(temp2);
                    s1.push(temp1);
                    temp1=temp1->left;
                    temp2=temp2->left;
                }
                if(s1.top==-1)
                {
                    break;
                }
                else
                {
                    temp1=s1.pop();
                    temp2=s2.pop();
                    temp1=temp1->right;
                    temp2=temp2->right;
                }
            }
        }

        void del()
        {
            node *temp,*s;
            int n;
            cout<<"enter node which u want to delete"<<endl;
            cin>>n;
            node *curr,*par;
            curr=root;
            par=root;
            while(n!=curr->data && curr!=NULL)
            {
                if(n<curr->data)
                {   
                    par=curr;
                    curr=curr->left;
                }
                else
                {   
                    par=curr;
                    curr=curr->right;
                }
            }
            if(curr==root) //curr is the one to be removed
            {
                if(curr->left==NULL) //single right child
                {
                    root=curr->right;
                }
                else if(curr->right==NULL) //single left child
                {
                    root=curr->left;
                }
                else if(curr->left!=NULL && curr->right!=NULL) //2 child case
                {
                    temp=curr->left;
                    root=curr->right;
                    s=curr->right;
                    while(s->left!=NULL)
                    {
                        s=s->left;
                    }
                    s->left=temp;
                }
                
            }
            else if(curr!=root && curr!=NULL)
            {
                if(curr->left==NULL && curr->right==NULL) // leaf node cond
                {
                    if(par->left==curr)
                    {
                        par->left==NULL;
                    }
                    else
                    {
                        par->right==NULL;
                    }
                }
                else if(curr->right==NULL) // node with single left child cond
                {
                    if(par->left==curr)
                    {
                        par->left=curr->left;
                    }
                    else
                    {
                        par->right=curr->left;
                    }
                }
                else if(curr->left==NULL) // node with single right child cond
                {
                    if(par->left==curr)
                    {
                        par->left=curr->right;
                    }
                    else
                    {
                        par->right=curr->right;
                    }
                }
                else // node with two child
                {
                    temp=curr->left;
                    s=curr->right;
                    while(s->left!=NULL)
                    {
                        s=s->left;
                    }
                    s->left=temp;
                    if(par->left==curr)
                    {
                        par->left=curr->right;
                    }
                    else
                    {
                        par->right=curr->right;
                    }
                }
                
            }
            else
            {
                cout<<"invalid operation !"<<endl;
            }
            if(curr!=NULL)
            {
                curr->left=NULL;
                curr->right=NULL;
                delete curr;
            }
        }
};

int main()
{   
    tree t1,t2;
    int n=0;
    while(n!=8)
    {   
        cout<<"enter choice:\n1.create\n2.display\n3.copy\n4.mirror\n5.depth\n6.height\n7.delete\n8.exit"<<endl;
        cin>>n;
        switch(n)
        {
            case 1:
                t1.create_tree();
                break;
            case 2:
                t1.display_dfs();
                break;
            case 3:
                t2.copy_tree(t1);
                t2.display_dfs();
                break;
            case 4:
                t1.mirror();
                break;
            case 5:
                t1.depth();
                break;
            case 6:
                t1.height();
                break;
            case 7:
                t1.del();
                break;
        }
    }
    return 0;
}