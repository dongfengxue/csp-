#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
    int m,n;
    map<int,int> mp;
    cin >>m;

    for(int i=0; i<m; i++)
    {
        cin>>n;
        mp[i]=n;
    }
    int num=0;
    map<int,int >::iterator ite,it2;
    for(ite=mp.begin(); ite!=mp.end(); ite++)
    {
        int a=ite->second;
        for(it2=ite; it2!=mp.end(); it2++)
        {

            int b=it2->second;
            if(a+b == 0)
                num++;
        }

    }

cout<<num<<endl;
}
