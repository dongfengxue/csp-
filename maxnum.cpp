#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main()
{
    int m,n;
    int sum;
    cin>>m;
    map<int,int> mp;
    for(int i=0; i<m; i++)
    {
        cin>>n;
        mp[n]++;

    }
    map<int,int>::iterator ite;
    int maxn=0,maxm;
    for(ite=mp.begin(); ite!=mp.end(); ite++)
    {
        if(ite->second > maxn)
        {

            maxn=ite->second;
            maxm=ite->first;
        }
    }
    //cout<<maxn;
    cout<<maxm;
    return 0;
}
