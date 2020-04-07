#include<iostream>
#include<ctype.h>
#define max 100
using namespace std;

class node
{
    char data;
    node *left;
    node *right;
    friend class stack;
    friend class tree;
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

class tree
{
    node *root;
    stack st;
    public:
        tree()
        {   
            root=new node(); //since we are initializing the root ourselves and not pointing to an already existing node.
            root->data='\0';
            root->left=NULL;
            root->right=NULL;
        }

        int length(char exp[]) //works without max which is better as otherwise useless memory gets allocated if size is smaller than max
        {
            int n,i;
            i=0;
            for(n=0;exp[n]!='\0';n++)
            {
                i++;
            }
            return i;
        }

        void create()
        {
            char postexp[max];
            cout<<"enter postfix expression : "<<endl;
            cin>>postexp;
            cout<<"entered expression is : "<<postexp<<endl;
            int len=length(postexp);
            cout<<"length of exp is "<<len<<endl;
            int i;
            for(i=0;i<len;i++)
            {   
                if(isalnum(postexp[i])) //operand case
                {
                    node *nnode;
                    nnode=new node();
                    nnode->data=postexp[i];
                    nnode->left=NULL;
                    nnode->right=NULL;
                    st.push(nnode);
                }
                else  //operator case
                {   
                    node *nnode;
                    if(postexp[i+1]=='\0')  //root node case
                    {
                        root->data=postexp[i];
                        nnode=root;
                    }
                    else   //non root case
                    {
                        nnode=new node();
                        nnode->data=postexp[i];
                    }
                    node *temp;
                    temp=st.pop();
                    nnode->right=temp;  //nnode here can either be the root node or any other sub node
                    temp=st.pop();
                    nnode->left=temp;
                    st.push(nnode);
                }
                
            }
            cout<<"binary tree creation successful !"<<endl;
        }

        void display()
        {   
            cout<<root->data<<endl;
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
};

int main()
{   
    tree t1;
    t1.create();
    t1.display(); //doing only dfs folks
    return 0;
}