#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t,a;
    vector <int> s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        s.push_back(a);
    }
    int max,temp;
    max=s[1]-s[0];
    if(max<0)
        max=-max;
    for(int i=0;i<t-1;i++)
    {
        temp=s[i+1]-s[i];
     if(temp<0)
        temp=-temp;
     if(temp>max)
        max=temp;
    }
cout<<max;
return 0;


}
