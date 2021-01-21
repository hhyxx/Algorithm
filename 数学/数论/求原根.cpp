int primes[N+10],cnt;
ll euler[N];
bool st[N+10];
vector<ll>ans;
vector<int> factors;//质因子集合，只有质数，没有指数
void get_primes(){
	st[1] = 1;
	euler[1] = 1;
	for (int i = 2; i <= N; i ++ ) {
		if (!st[i]) {
			primes[cnt++] = i;
			euler[i] = i - 1;
		}
		for (int j = 0; primes[j] <= N / i; j++) {
			int t = primes[j] * i;
			st[t] = true;
			if (i % primes[j] == 0) {
				euler[t] = euler[i] * primes[j];
				break;
			}
			euler[t] = euler[i] * (primes[j] - 1);
		}
	}
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int qmi(ll a,ll k,ll p){
	ll res=1;
	while(k){
		if(k&1) res=res*a%p;
		a=a*a%p;
		k>>=1;
	}
	return res;
}
void get_factors(int n)
{
	factors.clear();
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i) continue;
		factors.push_back(i);
		do n /= i;
		while (n % i == 0);
	}
	if (n > 1) factors.push_back(n);
}
//判断原根是否存在
bool judge(int n){
	// 模n有原根的充要条件是n=2,4,p^n,2p^n,其中p是奇素数，n为任意正整数
	if(n%2==0) n/=2;
	if(!st[n]) return true;//奇素数，有原根
	for(int i=3;i*i<=n;i++){//偶素数只有2，从3开始即可
		if(n%i==0){//遇到质因数除尽
			while(n%i==0) n/=i;
			return n==1;//能是有奇素数构成
		}
	}
	return false;
}
int main(){
    long long n;
    cin>>n;
    ans.clear();
    if(n==2){ puts("1");continue;}
    if(n==4){puts("3");continue;}
    if(!judge(n)) {puts("-1");continue;}//不存在原根
    int phi=euler[n];
    int aa=-1;//存最小的原根
    get_factors(phi);
    for(int a=2;a<n;a++){//求出一个最小的原根
        bool flag=true;
        aa=a;
        if(qmi(a,phi,n)!=1) continue;//原根定义进行判断剪枝
        for(int i=0;i<factors.size();i++){//枚举phi(n)的质因子
            if(qmi(a,phi/factors[i],n)==1){//即小于phi(n)/p[i]也满足等式，不是原根
                flag=false;
                break;
            }
        }
        if(flag){
            ans.pb(a);break;//a就是最小的原根
        }
    }
    if(ans.size()==0) puts("-1");
    else {
        for(int i=2;i<=phi;i++){//求所有的原根
            if(gcd(i,phi)==1) ans.pb(qmi(aa,i,n));
        }
        sort(ans.begin(),ans.end());
        unique(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            printf("%lld%c",ans[i],(i==ans.size()-1)?'\n':' ');
        }
    }
}