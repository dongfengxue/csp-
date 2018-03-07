
#include<iostream>
#include<vector>

using namespace std;

int main()
{
//vector <int> a;
    int a[6]= {1,2,6,5,7,4};
    int tmp;
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            if(a[i]<a[j])
            {
                tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
    for(int i=0; i<6; i++)
        cout<<a[i];
    cout<<endl;
    int low,high;
    low=0;
    high=6;
    int mid=(low+high)/2;
    int m;
    cin>>m;
    int num=0;
    while(low!=mid&&high!=mid)
    {
        if(a[mid]>m)
        {
            high=mid;
            mid=(low+mid)/2;
            num++;
        }
        else if(a[mid]<m)
        {
            low=mid;
            mid=(high+mid)/2;
            num++;
        }
        else
            {cout<<a[mid]<<" "<<num;
            break;
            }
    }
    cout<<num;


    return 0;
}

