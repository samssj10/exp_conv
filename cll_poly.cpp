#include<iostream>
using namespace std;

class node
{   
public:
    int coef;
    int exp;
    node *next;
    friend class poly;
};

class poly
{   
    public:
    node *head;
    poly()
    {
        head=new node();
        head->coef=0;
        head->exp=-1;
        head->next=head;
    }
    void createpoly()
    {
        node *curr,*temp=head;
        int n;//no of nodes
        cout<<"enter no of nodes"<<endl;
        cin>>n;
        cout<<"enter in decreasing order of exp"<<endl;
        int i;
        for(i=0;i<n;i++)
        {
            curr=new node();
            cout<<"enter coeff"<<endl;
            cin>>curr->coef;
            cout<<"enter exp"<<endl;
            cin>>curr->exp;
            curr->next=head;
            temp->next=curr;
            temp=curr;
        }
    }
    void display()
    {
      node *temp,*prev;
      temp=head->next;
      while(temp!=head)
      { 
        cout<<temp->coef<<"x^"<<temp->exp;
        if(temp->next!=head)
        {
            cout<<"+";
        }
        temp=temp->next;
      }  
    }
    void add(poly p1,poly p2)
    {   
        node *t,*t1,*t2;
        t=head;
        t1=p1.head->next;
        t2=p2.head->next;
        while(t1!=p1.head || t2!=p2.head)
        {
            if(t1->exp>t2->exp)
            {   
                node *nterm;
                nterm=new node();
                nterm->coef=t1->coef;
                nterm->exp=t1->exp;
                t->next=nterm;
                t=nterm;
                t1=t1->next;
            }
            else if(t1->exp<t2->exp)
            {   
                node *nterm;
                nterm=new node();
                nterm->coef=t2->coef;
                nterm->exp=t2->exp;
                t->next=nterm;
                t=nterm;
                t2=t2->next;
            }
            else
            {
                node *nterm;
                nterm=new node();
                nterm->coef=t1->coef+t2->coef;
                nterm->exp=t1->exp;
                t->next=nterm;
                t=nterm;
                t1=t1->next;
                t2=t2->next;
            }
        }
        t->next=head;
    }
    void eval(int x)
    {
        node *temp;
        temp=head->next;
        int res=0;
        while(temp!=head)
        {
            int b=1;
            while(temp->exp!=0)
            {
                b=b*x;
                --temp->exp;
            }
            res=res+(temp->coef*b);
            temp=temp->next;
        }
        cout<<"eval result is "<<res<<endl;
    }
    void mul(poly p1,poly p2)
    {
        node *t,*t1,*t2;
        t=head;
        t1=p1.head->next;
        t2=p2.head->next;
        while(t1!=p1.head)
        {   
            node *temp;//for traversing p2 for each term in p1 
            temp=t2;
            while(temp!=p2.head)
            {
                node *nterm;
                nterm=new node();
                nterm->coef=t1->coef*temp->coef;
                nterm->exp=t1->exp+temp->exp;
                t->next=nterm;
                t=nterm;
                temp=temp->next;
            }
            t1=t1->next;
        }
        t->next=head;
    }

    void check_same()
    {
        node *curr,*temp,*prev;
        curr=head->next;
        while(curr!=head)
        {
            temp=curr->next;
            prev=curr;
            while(temp!=head)
            {
                if(curr->exp==temp->exp)
                {
                    curr->coef=curr->coef+temp->coef;
                    prev->next=temp->next;
                    delete temp;
                }
                temp=temp->next;
                prev=prev->next;
            }
            curr=curr->next;
        }
    }   
};



int main()
{
    poly p1,p2,p3;
    p1.createpoly();
    p2.createpoly();
    //p3.add(p1,p2);
    p3.mul(p1,p2);
    p3.check_same();
    p3.display();
    /*int x;
    cout<<"enter value of x for evaluation"<<endl;
    cin>>x;
    p1.eval(x);*/
    return 0;
}