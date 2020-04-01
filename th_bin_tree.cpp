#include<iostream>
using namespace std;

class node
{
    char data;
    node *left;
    node *right;
    bool lbit;
    bool rbit;
    friend class tree;
    public:
        node()
        {
            lbit=1;
            rbit=1;
        }
};

class tree
{
    node *head;
    node *root;
    public:
        tree()
        {   
            head=new node();
            head->data='\0';
            head->rbit=0; //since head->right always points to head only
            head->left=head;
            head->right=head;
        }

        void create()
        {   
            root=new node();
            cout<<"enter root value "<<endl;
            cin>>root->data;
            head->lbit=0;
            head->left=root;
            root->left=head;
            root->right=head;
            node *curr;
            curr=root;
            char ch; // ask user whether he wants to insert node
            do
            {   
                curr=root; //curr gets manipulated for each node insertion so we need to initialize
                cout<<"do u want to insert node ?"<<endl;
                cin>>ch;
                if(ch=='y') //otherwise memory gets allocated uselessly
                {
                    char c;
                    int flag=0;
                    while(flag==0)
                    {   
                        cout<<"where do u want to insert ?"<<endl;
                        cin>>c;
                        if(c=='l')
                        {
                            if(curr->lbit==1)
                            {
                                node *nnode;
                                nnode=new node();
                                cout<<"enter data"<<endl;
                                cin>>nnode->data;
                                nnode->left=curr->left;
                                nnode->right=curr;
                                curr->lbit=0;
                                curr->left=nnode;
                                flag=1;
                            }
                            else
                            {
                                curr=curr->left;
                            }
                            
                        }
                        if(c=='r')
                        {
                            if(curr->rbit==1)
                            {
                                node *nnode;
                                nnode=new node();
                                cout<<"enter data"<<endl;
                                cin>>nnode->data;
                                nnode->left=curr;
                                nnode->right=curr->right;
                                curr->rbit=0;
                                curr->right=nnode;
                                flag=1;
                            }
                            else
                            {
                                curr=curr->right;
                            }
                        }
                            
                    }
                }
            } while (ch=='y');

             
        }

        void display()
        {
            int n;
            cout<<"how do u want to display :\n1.inorder\n2.preorder\n"<<endl;
            cin>>n;
            
        }

};

int main()
{   
    tree t1;
    t1.create();
    return 0;
}