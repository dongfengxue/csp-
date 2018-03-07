#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector <int> a;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    int sum=0;
    int max=a[0];
    for(int i=0;i<a.size();i++)
        {
    		if(sum>0)
        	  sum=sum+a[i];
        	else
               sum=a[i];
        	if(sum>max)
                max=sum;
	    }
    cout<<max;
    return 0;

}
