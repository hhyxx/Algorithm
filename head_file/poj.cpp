#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;


#define close ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define fi first
#define se second 
#define ll long long
#define pb push_back


typedef pair<long long,long long> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef double db;


const ll mod=1e9+7;


ll powmod(ll a,ll b,ll p)
{
    ll res=1;
    a%=p;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
ll gcd(ll a,ll b) 
{
    return b?gcd(b,a%b):a;
}

int _;

void solve()
{
    
}

int main(){
    close 
    cin>>_;
    while(_--) solve();
}


