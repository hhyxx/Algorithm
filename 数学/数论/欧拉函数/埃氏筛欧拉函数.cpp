/*
a,b若gcd(a,b)=1，则a,b互质。
欧拉函数的定义：1～N中与N互质的数的个数成为欧拉函数，通常为phi(N)
若N分解质因数后为(p1^c1) * (p2 ^c2) * ....*(pm ^cm)
求欧拉函数公式：phi(N) = N * (1-1/p1) * (1-1/p2)* ...(1-1/pm)
*/ 
/*
性质：
1）任意的n>1，1～n中与n互质的数的和为 n * φ(n) /2
2）若a，b互质，则φ(a*b) = φ(a) * φ(b)
3）若ƒ是积性函数，且在算数基本定理中,n=∏(i=1:m) pici , 则ƒ(n)=∏(i=1:m)ƒ( pici )
4）若p为质数，若p｜n且p2｜n，则φ(n)=φ(n/p)*p
5）设p为质数，若p｜n但p2 ! | n，则φ(n)=φ(n/p)*(p-1) 
6）∑(d|n) φ(d)=n
*/

// O（N） 求1～N 中每一个数的欧拉函数
// 线性筛法求欧拉函数
int primes[N], cnt;        // primes[]存储所有素数
int phi[N];            // 存储每个数的欧拉函数
bool st[N];            // st[x]存储x是否被筛掉

void get_eulers(int n){
    rep(i,2,n) phi[i]=0;
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!phi[i]){
            for(int j=i;j<=n;j+=i){
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}