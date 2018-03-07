#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> a;
    int m;
    for(int i=0;i<n;i++){
        cin>>m;
        a.push_back(m);
    }
    int min_=10000;
    int dif;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            dif=a[i]-a[j];
            if(dif<0)
                dif=-dif;
            if(dif<min_)
                min_=dif;
        }
    }
    cout<<min_<<endl;
    return 0;


}
