#include<iostream>
#define max 100
using namespace std;

class node
{
    int data;
    node *left,*right;
    friend class tree;
    friend class stack;
    friend class queue;
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
    stack st;
    queue q;
    public:
        tree()
        {
            root=new node();
           // cout<<"enter root value of your tree"<<endl;
            root->data=0;
            root->left=NULL;
            root->right=NULL;
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
            for(i=1;i<=n;i++)
            { 
                create_rem(temp);
            }
        }

        void create_rem(node *temp) 
        {
            node *curr;
            curr=temp;
            char c; //choice
            cout<<"where do u want to insert"<<endl;
            cin>>c;
            if(c=='l')
            {   
                if(curr->left==NULL)
                {
                    node *nnode;
                    nnode=new node();
                    cin>>nnode->data;
                    nnode->left=NULL; //user cannot skip position if free
                    nnode->right=NULL;
                    curr->left=nnode;
                }
                else
                {
                    create_rem(curr->left);
                }
                
            }
            if(c=='r')
            {
                if(curr->right==NULL)
                {
                    node *nnode;
                    nnode=new node();
                    cin>>nnode->data;
                    nnode->left=NULL;
                    nnode->right=NULL;// also not works properly for l,r,r,l and r,l,l,r
                    curr->right=nnode;
                }
                else
                {
                    create_rem(curr->right);
                }
            }
        }

        void create_tree() 
        {                  
            node *curr;
            cout<<"enter root value of your tree"<<endl;
            cin>>root->data;
            curr=root;
            char ch;// ask user abt insertion
            do
            {   
                curr=root;// required as curr gets manipulated after each insertion
                cout<<"do u wish to insert a node ?"<<endl;
                cin>>ch;
                if(ch=='y')
                {   
                    char c; //ask user abt postion
                    int flag=0;
                    while(flag==0)
                    {  
                        cout<<"where do u want to insert ?"<<endl;
                        cin>>c;
                        if(c=='l')
                        {
                            if(curr->left!=NULL)
                            {
                                curr=curr->left;
                            }
                            else
                            {
                                node *nnode;
                                nnode=new node();
                                cin>>nnode->data;
                                nnode->left=NULL;
                                nnode->right=NULL;
                                curr->left=nnode;
                                flag=1;
                            }
                            
                        }
                        if(c=='r')
                        {
                            if(curr->right!=NULL)
                            {
                                curr=curr->right;
                            }
                            else
                            {
                                node *nnode;
                                nnode=new node();
                                cin>>nnode->data;
                                nnode->left=NULL;
                                nnode->right=NULL;
                                curr->right=nnode;
                                flag=1;
                            }
                        }
                    }
                }
            }while(ch=='y');
            
        }

        void display_dfs() //Binary Traversals
        {   
            int n;
            cout<<"how do u want to display:\n1.inorder(rec)\n2.preorder(rec)\n3.postorder(rec)\n4.inorder(non-rec)\n5.preorder(non-rec)\n6.postorder(non-rec)\n"<<endl;
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
                case 4:
                    inorder(root);
                    break;
                case 5:
                    preorder(root);
                    break;
                case 6:
                    postorder(root);
                    break;
            }
        }

        void inorder_rec(node *temp)
        {
            if(temp!=NULL)
            {
                inorder_rec(temp->left);
                cout<<temp->data;
                inorder_rec(temp->right);
            }
        }
        
        void preorder_rec(node *temp)
        {
            if(temp!=NULL)
            {
                cout<<temp->data;
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
                cout<<temp->data;
            }
        }

        void inorder(node *temp)
        {   
            while(1)
            {   
                while(temp!=NULL)
                {
                    st.push(temp);
                    temp=temp->left;
                }
                if(st.top==-1) //stack is empty
                {
                    break;
                }
                temp=st.pop();
                cout<<temp->data;
                temp=temp->right;
            }
        }

        void preorder(node *temp)
        {
            while(1)
            {
                while(temp!=NULL)
                {
                    cout<<temp->data;
                    st.push(temp);
                    temp=temp->left;
                }
                if(st.top==-1)
                {
                    break;
                }
                temp=st.pop();
                temp=temp->right;
            }
        }

        void postorder(node *temp)
        {
            while(1)
            {
                while(temp!=NULL)
                {
                    st.push(temp);
                    temp=temp->left;
                }
                if(st.data[st.top]->right==NULL)
                {
                    temp=st.pop();
                    cout<<temp->data;
                }
                while((st.top!=-1) && st.data[st.top]->right==temp)
                {
                    temp=st.pop();
                    cout<<temp->data;
                }
                if(st.top==-1)
                {
                    break;
                }
                temp=st.data[st.top]->right;
            }
        }

        void display_bfs()
        {   
            node *temp;
            temp=root;
            q.enqueue(temp);
            while(q.front!=q.rear)
            {
                temp=q.dequeue();
                cout<<temp->data;
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

};

int main()
{
    tree t1;
    t1.create_tree();
    t1.display_dfs();
    //t1.display_bfs();
    return 0;
}