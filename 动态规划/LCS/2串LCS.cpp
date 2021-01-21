/*

*/

#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)

const int N=1010;

int dp[N][N];
int n,m;
char a[N],b[N];
int main()
{
    cin>>n>>m;
    cin>>a+1;
    cin>>b+1;

    rep(i,1,n+1) rep(j,1,m+1)
    {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
    cout<<dp[n][m]<<endl;
}
























