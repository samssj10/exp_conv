#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    string b;
    int c=0;
    cout<<"enter a string\n";
    cin>>b;
    int i,j=0;
    for(i=0;b[i]!='\0';i++)
    {
        if(b[i]!=' ')
        {
            j++;
            b[j]=b[i];
        }
    }
    cout<<b;
    stringstream geek(b);
    geek>>c;
    cout<<c;
    return 0;
}