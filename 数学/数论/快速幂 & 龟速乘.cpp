// 龟速乘：乘法取模的时候溢出
//O(log k)
ll qmul(ll a, ll k, ll p){
    ll res=0;
    while(k){
        if(k&1) res=(res+a)%p;
        a=(a+a)%p;
        k>>=1;
    }
    return res;
}
//快速幂
// O(log k)
ll qmi(ll a,ll k, ll p){
    ll ans=1;
    while(k){
        if(k&1)
            ans=ans*a%p;
        a=a*a%p;
        k>>=1;
    }
    return ans;
}