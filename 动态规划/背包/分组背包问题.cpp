
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)

const int N=110;
int n,m;
int dp[N],w[N],v[N];

int main()
{
    cin>>n>>m;
    rep(i,1,n+1)
    {
        int s;cin>>s;
        rep(j,1,s+1) cin>>w[j]>>v[j];
        per(j,0,m+1) rep(k,1,s+1)
        {
            if(j>=w[k]) dp[j]=max(dp[j],dp[j-w[k]] + v[k]);
        }
    }
    cout<<dp[m]<<endl;
}
























