/*
O(n^3)
*/


#include<bits/stdc++.h>
using namespace std;

const int N=110;
int f[N];
int v[N],w[N],s[N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i]>>s[i];

    for(int i=1;i<=n;i++)
        for(int j=m;j>=0;j--){
            for(int k=0;k<=s[i] && k*v[i] <=j;k++)
                f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
        }

    cout<<f[m]<<endl;
    return 0;
}
























