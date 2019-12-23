#include<iostream>
using namespace std;
int main()
{
    int d[7];// 4 bit dataword + 3 zeros =augmented dataword
    int i;
    cout<<"enter 4 bit dataword"<<endl;
    for(i=6;i>=3;i--)
    {
        cin>>d[i]; // user entering dataword
    }
    d[2]=0;
    d[1]=0;
    d[0]=0;
    cout<<"Augmented dataword is :"<<endl;
    for(i=6;i>=0;i--)
    {
        cout<<d[i]<<endl;
    }
    int div[4]; // 4 bit divisor
    cout<<"enter 4 bit divisor"<<endl;
    for(i=3;i>=0;i--)
    {
        cin>>div[i];
    }
    int sub_res[4];
    sub_res[3]=d[6];
    sub_res[2]=d[5];
    sub_res[1]=d[4];
    sub_res[0]=d[3];
    int cnt=3;

    for(i=0;i<3;i++)
    {
        if(sub_res[3]==1)
        {
            cnt--;
            sub_res[3]=sub_res[2]^div[2];
            sub_res[2]=sub_res[1]^div[1];
            sub_res[1]=sub_res[0]^div[0];
            sub_res[0]=d[cnt];
        }
        else
        {   
            cnt--;
            sub_res[3]=sub_res[2]^0;
            sub_res[2]=sub_res[1]^0;
            sub_res[1]=sub_res[0]^0;
            sub_res[0]=d[cnt];
        }
    }
    cout<<"rem cal at sender side = "<<endl;
    for(i=3;i>=0;i--)
    {
        cout<<sub_res[i]<<endl;
    }
    d[2]=sub_res[2];
    d[1]=sub_res[1];
    d[0]=sub_res[0];
    cout<<"codeword sent at receiver side :"<<endl;
    for(i=6;i>=0;i--)
    {
        cout<<d[i]<<endl;
    }
    int c[7];// 7 bit codeword received at receiver side
    cout<<"enter codeword received"<<endl;
    for(i=6;i>=0;i--)
    {
        cin>>c[i];
    }
    int sub_res2[4];
    sub_res2[3]=c[6];
    sub_res2[2]=c[5];
    sub_res2[1]=c[4];
    sub_res2[0]=c[3];
    int cnt2=3;

    for(i=0;i<3;i++)
    {
        if(sub_res2[3]==1)
        {
            cnt2--;
            sub_res2[3]=sub_res2[2]^div[2];
            sub_res2[2]=sub_res2[1]^div[1];
            sub_res2[1]=sub_res2[0]^div[0];
            sub_res2[0]=c[cnt2];
        }
        else
        {   
            cnt2--;
            sub_res2[3]=sub_res2[2]^0;
            sub_res2[2]=sub_res2[1]^0;
            sub_res2[1]=sub_res2[0]^0;
            sub_res2[0]=c[cnt2];
        }
    }
    cout<<"rem cal at receiver side = "<<endl;
    for(i=3;i>=0;i--)
    {
        cout<<sub_res2[i]<<endl;
    }
    if(sub_res2[2]==0 && sub_res2[1]==0 && sub_res2[0]==0)
    {
        cout<<"no error in data received"<<endl;
    }
    else
    {
        cout<<"error in received data"<<endl;
    }
    return 0;
}   

/*OUTPUT
enter 4 bit dataword
1
0
0
1
Augmented dataword is :
1
0
0
1
0
0
0
enter 4 bit divisor
1
0
1
1
rem cal at sender side = 
0
1
1
0
codeword sent at receiver side :
1
0
0
1
1
1
0
enter codeword received
1
0
0
0
1
0
1
rem cal at receiver side = 
1
0
1
1
error in received data
samssj10@Laptop:~$ g++ crc.cpp
samssj10@Laptop:~$ ./a.out
enter 4 bit dataword
1   
0
0
1
Augmented dataword is :
1
0
0
1
0
0
0
enter 4 bit divisor
1
0
1
1
rem cal at sender side = 
0
1
1
0
codeword sent at receiver side :
1
0
0
1
1
1
0
enter codeword received
1
0
0
1
1
1
0
rem cal at receiver side = 
0
0
0
0
no error in data received
*/