#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;
int main()
{
 int nf,N;  //nf=no of frames , N=window size
 int no_tr=0; // no of transmissions
 srand(time(NULL));// should be run exactly once to intialise the PRNG. Do this in Main when the application starts.
 cout<<"Enter the number of frames\n";
 cin>>nf;
 int m;
 cout<<"Enter seq no field in bits\n";
 cin>>m;
 N=(pow(2,m))-1;
 cout<<"window size = "<<N<<endl;
 int i=1;// to track the number of frames sent
 while(i<=nf)
 {
     int x=0;//to keep track of ack recd or not
     for(int j=i;j<i+N && j<=nf;j++)
     {
         cout<<"Sent Frame "<<j<<endl;
         no_tr++;
     }
     for(int j=i;j<i+N && j<=nf;j++)
     {
         int flag = rand()%2;
         if(!flag)
             {
                cout<<"Acknowledgment sent for Frame "<<j<<endl;
                int temp = rand()%2;// check whether ack is recd or gets corrupted/lost from reveiver to sender
                if(!temp)
                {   
                    cout<<"Acknowledgement received for frame"<<j<<endl;
                    x++;
                }
             }
         else
             {  
                cout<<"Frame "<<j<<" Not Received"<<endl; //frame gets corruted or is lost or is out of order from sender to receiver 
                cout<<"Retransmitting Window"<<endl;
                break;
             }
     }
     cout<<endl;
     i+=x;
 }
 cout<<"Total number of transmissions : "<<no_tr<<endl;
 return 0;
}

