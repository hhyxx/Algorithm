/*
dp[i][j] 表示只考虑前i个物品,体积为j的背包能装的最大价值
result = max { f[n][0~v] }

1. 不选第i个物品
f[i][j] = f[i-1][j];

2. 选第i个物品 
f[i][j] = f[i-1][j-v[i]] + w[i]
f[i][j]=max (1,2) 

时间复杂度 O(vw)
*/



#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
const int N=1010;
int v[N],w[N];
int n,m;
int dp[N][N]; 
int main()
{
    memset
    cin>>n>>m;
    rep(i,1,n+1) cin>>w[i]>>v[i];

    rep(i,1,n+1)
        rep(j,1,m+1)
        {
            dp[i][j]=dp[(i-1)][j];
            if(j>=w[i])
                dp[i][j]=max(dp[i][j],dp[(i-1)][j-w[i]]+v[i]);
        }
    cout<<dp[n][m];
}

int dp[N];
int main()
{
    cin>>n>>m;
    rep(i,1,n+1) cin>>w[i]>>v[i];
    dp[0]=0;
    rep(i,1,n+1)
        per(j,w[i],m+1)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    cout<<dp[m]<<endl;
    return 0;
}

// 滚动数组
int dp[2][N];
int main()
{
    cin>>n>>m;
    rep(i,1,n+1) cin>>w[i]>>v[i];
    rep(i,1,n+1) rep(j,1,m+1)
    {
        dp[i&1][j]=dp[(i-1)&1][j];
        if(j>=w[i]) dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j-w[i]]+v[i]);
    }
    cout<<dp[n&1][j]<<endl;
}

