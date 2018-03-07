#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    string line;
    cin>>line;

    int a[10];
    a[0]=line[0]-'0';
    a[1]=line[2]-'0';
    a[2]=line[3]-'0';
    a[3]=line[4]-'0';
    a[4]=line[6]-'0';
    a[5]=line[7]-'0';
    a[6]=line[8]-'0';
    a[7]=line[9]-'0';
    a[8]=line[10]-'0';
    a[9]=line[12]-'0';

    int sum=0;
    char checksum;
    for(int i=0; i<9; i++)
    {
        sum=sum+a[i]*(i+1);
    }
    if(a[9] == sum%11)
        cout<<"Right"<<endl;
    else
    {
        if(sum%11 == 10)
        {
            checksum='X';
            line[12]=checksum;
            cout<<line<<endl;
        }
        else
        {
            checksum=sum%11;
            line[12]=checksum +'0';
            cout<<line<<endl;
        }
    }
    return 0;


}
