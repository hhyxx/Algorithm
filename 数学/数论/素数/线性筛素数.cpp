

// 线性筛质数
// O（n）
// 1～n质数的上界是n/In(n)

int primes[N],cnt;
bool st[N];

void get_primes(int n)
{
    rep(i,2,n+1)
    {
        if(!st[i]) primes[++cnt]=i;
        for(int j=1;primes[j]<=n/j;j++)
        {
            st[primes[j]*i]=1;
            if(i%primes[j]==0) break;
        }
    }
}