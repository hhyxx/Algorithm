/*

第i个物品体积、价值、数量 为 v,w,s

每个物品分成log s 份

用这log s份可以拼凑出s这个数字

O(n * log s * v) 

*/


#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first 
#define se second 
#define pb push_back
using namespace std;
const int N=2010;
int f[N];
int n,m;

int main(){
    vector<pii> goods;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int v,w,s;
        cin>>v>>w>>s;

        for(int k=1;k<=s;k*=2){
            s-=k;
            goods.pb({v*k,w*k});
        }
        if(s>0) goods.pb({v*s,w*s});
    }

    for(auto it:goods)
        for(int j=m;j>=it.fi;j--)
            f[j]=max(f[j],f[j-it.fi]+it.se);
    cout<<f[m]<<endl;
    return 0;    
}
























