/*
与01背包的主要是每种物品可以选取无限次，背包体积有限

一个简单的优化，去除掉 价值相同或更小 但是重量更大的 ，显然对最大值的结果不会影响


result = max { f[0......m]}

数学归纳 （k-1） 个 i个物品确定

那么当选k个物品最优时一定会遍历到这种情况
*/


// O(n^2)

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
const int N=1010;

int v[N],w[N];

int dp[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,1,n+1) cin>>v[i]>>w[i];

    rep(i,1,n+1) rep(j,1,m+1)
    {
        dp[i][j]=dp[i-1][j];
        if(j>=v[i]) dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+w[i]);
    }
    cout<<dp[n][m];
}   

int dp[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    rep(i,1,n+1)
        rep(j,v[i],m+1)// 因为物品i 可以无限次的选取所以，不同的容量状态的只要取其中的最大值就可以
            dp[j]=max(dp[j],dp[j-v[i]] + w[i] );
    cout<<dp[m]<<endl;
}
























