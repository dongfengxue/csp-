#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define mod 1000000007
//typedef long long l;
int main()
{
  //  long long l;
    long long dp[1001][6];
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        /*dp[i][0]=1;
        dp[i][1]=(dp[i-1][1]*2+dp[i-1][0])%mod;
        dp[i][2]=(dp[i-1][2]+dp[i-1][0])%mod;
        dp[i][3]=(dp[i-1][3]*2)%mod+dp[i-1][1]%mod;
        dp[i][4]=(dp[i-1][4]*2)%mod+(dp[i-1][1]+dp[i-1][2])%mod;
        dp[i][5]=(dp[i-1][5]*2)%mod+(dp[i-1][4]+dp[i-1][3])%mod;
        */
        dp[i][0]=1;//ֻ��2
        dp[i][1]=(2*dp[i-1][1]%mod+dp[i-1][0])%mod;//ֻ��2��0  ĩβ0��2��ĩβ0
        dp[i][2]=(dp[i-1][2]+dp[i-1][0])%mod;//ֻ��2��3 ĩβ3
        dp[i][3]=(2*dp[i-1][3]%mod+dp[i-1][1])%mod;//ֻ��2��0��1 ĩβ2��1��ĩβ1
        dp[i][4]=((2*dp[i-1][4]%mod+dp[i-1][2])%mod+dp[i-1][1])%mod;//ֻ��2��0��3 ĩβ1��3��ĩβ0��ĩβ3
        dp[i][5]=((2*dp[i-1][5]%mod+dp[i-1][4])%mod+dp[i-1][3])%mod;//��4������  ĩβ1��3
    }
    cout<<dp[n][5];
    return 0;
}
