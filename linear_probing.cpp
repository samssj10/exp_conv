#include<iostream>
#define max 100
using namespace std;

class student
{
    int roll_no;
    string name;
    char grade;
    friend class hashing;
    public:
        student()
        {
            roll_no=-1;
            name='\0';
            grade='\0';
        }
};

class hashing
{
    student s[max];
    public:
    void linear_without()
    {   
        student curr;
        int index,i,flag;
        char ch='y';
        while(ch=='y')
        {   
            cout<<"enter student details : 1.name 2.roll no 3.grade "<<endl;
            cin>>curr.name>>curr.roll_no>>curr.grade;
            index=(curr.roll_no)%max; //dont change this
            if(s[index].roll_no==-1)
            {
                s[index]=curr;
            }
            else
            {
                i=1;
                i=(index+i)%max;
                while(i!=index)
                {
                    if(s[i].roll_no==-1)
                    {
                        s[i]=curr;
                        flag=1;
                        break;
                    }
                    i=(i+1)%max;
                }
                if(flag==0)
                {
                    cout<<"hash table is full ! "<<endl;
                }
            }
            cout<<"do u want to continue ? "<<endl;
            cin>>ch;
        }
    }

    void linear_with()
    {
        student curr,temp;
        int index,i,flag;
        char ch='y';
        while(ch=='y')
        {   
            cout<<"enter student details : 1.name 2.roll no 3.grade "<<endl;
            cin>>curr.name>>curr.roll_no>>curr.grade;
            index=(curr.roll_no)%max; //dont change this
            if(s[index].roll_no==-1)
            {
                s[index]=curr;
            }
            else
            {   
                temp=curr;
                if(index!=(s[index].roll_no)%max) //not home add
                {
                    temp=s[index];
                    s[index]=curr;
                }
                i=1;
                i=(index+i)%max;
                while(i!=index)
                {
                    if(s[i].roll_no==-1)
                    {
                        s[i]=temp;
                        flag=1;
                        break;
                    }
                    i=(i+1)%max;
                }
                if(flag==0)
                {
                    cout<<"hash table is full ! "<<endl;
                }
            }
            cout<<"do u want to continue ? "<<endl;
            cin>>ch;
        }
    }
    
    void display()
    {
        int i;
        cout<<"student records are : "<<endl;
        for(i=0;i<max;i++)
        {   
            if(s[i].roll_no!=-1)
            {   
                cout<<s[i].name<<" "<<s[i].roll_no<<" "<<s[i].grade<<endl;
            }
        }
    }
};

int main()
{   
    hashing h1;
    h1.linear_with();
    h1.display();
    return 0;
}