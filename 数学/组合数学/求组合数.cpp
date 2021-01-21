// 递推所有组合数,C(n,m)=C(n-1,m-1)+C(n-1,m)
// O(n^2)
int c[N][N];
void init(){
    for (int i = 0; i <N ; ++i) {
        for (int j = 0; j <=i ; ++j) {
            if(!j) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}

//预处理所有阶乘和其逆元，模数质数用费马小定理，非质数扩展欧求逆元
// O(n)
void init(){
	fact[0]=infact[0]=1;
	for (int i = 1; i <N ; ++i) {
		fact[i] = (LL)fact[i-1]*i %mod;
		infact[i]=(LL)infact[i-1] * qmi(i,mod-2,mod)%mod;
	}
}


//Lucas
//O(log(p)N * P * log P)
ll qmi( a,int k){
    int res=1;
    while(k){
        if(k&1)   res=(LL)res*a%p;
            a=(LL)a*a%p;
            k>>=1;
    }
    return res;
}
int C(int a,int b){
    int res=1;
    for (int i = 1,j=a; i <=b ; ++i,j--) 
    {
        res=(LL)res*j%p;
        res=(LL)res*qmi(i,p-2)%p;
    }
    return res;
}
int lucas(LL a,LL b){
    if(a<p&&b<p) return C(a,b);
    else return (LL)C(a%p,b%p)*lucas(a/p,b/p)%p;
}


// exlucas1 
// 先打表看质因数，质因子次数都为1时
ll a[N];
int primes[N],cnt;
ll qmi(ll a,ll b,ll p){
	ll res=1;
	while(b){
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
ll CRT(){
	ll M=1;
	for(int i=1;i<=4;i++){
		M*=primes[i];
	}
	ll res=0;
	for(int i=1;i<=4;i++){
		ll x,y;
		ll tmp=M/primes[i];
		exgcd(tmp,primes[i],x,y);
		res=(res+tmp*x*primes[i])%M;
	}
	return ((res+M)%M)%M;
}
ll C(ll a,ll b,ll p){
    ll res=1;
    for (ll i = 1,j=a; i <=b ; ++i,j--) {
        res=res*j%p;
        res=res*qmi(i,p-2,p)%p;
    }
    return res;
}
ll lucas(ll n,ll m,ll p){
	if(n<m) return 0;if(!n) return 1;
	if(n<p&&m<p) return C(n,m,p);
	return (ll)C(n%p,m%p,p)*lucas(n/p,m/p,p)%p;
}
int main(){
    cin>>n>>m;
	for(int i=0;i<cnt;i++){
			a[i]=(a[i]+lucas(n,m,primes[i]))%primes[i];
	}
	ll ans=CRT();
}



//exlucas2
ll exgcd(ll a,ll b,ll &x, ll &y){
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
ll gcd(ll a,ll b){ b?gcd(b,a%b):a;}
ll inv(ll a,ll p){
	ll x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}
ll qmi(ll a,ll b,ll p){
	ll res=1;
	a%=p;
	while (b){
		if (b&1LL) res=res*a%p;
		b>>=1LL;
		a=a*a%p;
	}
	return res;
}
ll f(ll n,ll p,ll pk){
	if (n==0) return 1;
	ll x=1;//循环节
	ll y=1;//余项
	for (ll i=1;i<=pk;i++){
		if (i%p) x=x*i%pk;
	}
	x=qmi(x,n/pk,pk);
	for (ll i=pk*(n/pk);i<=n;i++){
		if (i%p) y=y*(i%pk)%pk;
	}
	return f(n/p,p,pk)*x%pk*y%pk;
}
ll g(ll n,ll p){
	if (n<p) return 0;
	return g(n/p,p)+(n/p);
}
ll C_pk(ll n,ll m,ll p,ll pk){
	ll fz=f(n,p,pk);
	ll fm1=inv(f(m,p,pk),pk);
	ll fm2=inv(f(n-m,p,pk),pk);
	ll mi=qmi(p,g(n,p)-g(m,p)-g(n-m,p),pk);
	return fz*fm1%pk*fm2%pk*mi%pk;
}
ll m_[1001],a[1001];
//x=a(mod m_)
ll exlucas(ll n,ll m,ll mod){
	ll t=mod,cnt=0;
	for (ll i=2;i<=mod/i;i++){//分解质因数
		if (!(t%i)){
			ll c=1;
			while (t%i==0){
				c*=i;t/=i;
			}
			m_[++cnt]=c;a[cnt]=C_pk(n,m,i,c);
		}
	}
	if (t!=1){
		m_[++cnt]=t;a[cnt]=C_pk(n,m,t,t);
	}

	ll ans=0;
	for (ll i=1;i<=cnt;i++){ // CRT
		ll M=mod/m_[i],M_=inv(M,m_[i]);
		ans=(ans+a[i]*M%mod*M_%mod)%mod;
	}
	return (ans%mod+mod)%mod;//最小的值
}