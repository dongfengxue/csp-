#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

int main()
{

    int m,n;
    cin>>n;
    map<int,int> a;

//int a[1000];
    int max_height=0;
    for(int i=0; i<n; i++)
    {
        cin>>m;
        a[i]=m;
        if(a[i]>max_height)
            max_height=a[i];
    }
    map<int,int>::iterator ite;
    int s=0,sum=0;
    int flag=0;
    //sum=n;
    for(int j=1; j<max_height; j++)
    {
            int sum_num=0,num=0;
        for(ite=a.begin(); ite!=a.end(); ite++)
        {


            if(ite->second >=j )
            {
                num++;
            }
            else
            {
                num=0;
            }
            if(num>sum_num)
                sum_num=num;        //保存最大的连续个数
        }
        if(sum_num*j > sum)
            sum=sum_num*j;              //sum是最大矩形面积值
    }
    cout<<sum;
    return 0;

}
