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
        dp[i][0]=1;//Ö»º¬2
        dp[i][1]=(2*dp[i-1][1]%mod+dp[i-1][0])%mod;//Ö»º¬2¡¢0  Ä©Î²0»ò2¡¢Ä©Î²0
        dp[i][2]=(dp[i-1][2]+dp[i-1][0])%mod;//Ö»º¬2¡¢3 Ä©Î²3
        dp[i][3]=(2*dp[i-1][3]%mod+dp[i-1][1])%mod;//Ö»º¬2¡¢0¡¢1 Ä©Î²2»ò1¡¢Ä©Î²1
        dp[i][4]=((2*dp[i-1][4]%mod+dp[i-1][2])%mod+dp[i-1][1])%mod;//Ö»º¬2¡¢0¡¢3 Ä©Î²1»ò3¡¢Ä©Î²0¡¢Ä©Î²3
        dp[i][5]=((2*dp[i-1][5]%mod+dp[i-1][4])%mod+dp[i-1][3])%mod;//º¬4¸öÊý×Ö  Ä©Î²1»ò3
    }
    cout<<dp[n][5];
    return 0;
}
