// 逆元即 a * x ≡ 1 （mod p），a,p互质，其中x称做a mod p 的乘法逆元
// 有了模n意义下的逆元，可以将a/b在模n下问题转化为 a * b的逆元

//扩展欧几里得求逆元 O（log p）
/*
   a * x ≡ 1 （mod p）
=> a * x + p * y = 1
这个方程有解的充要条件是 gcd(a,p) | 1 即gcd(a,p) = 1
即 a，p互质的时候有解
*/
int exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
//x即为逆元


// 快速幂求逆元 O（log(P-2)）
// 只有p是质数才可以使用
/* 
当 p 是质数的时候 
费马小定理 a ^ (p-1) ≡ 1(mod p) 
应用费马小定理可以得到
a * a^(p-2) ≡ 1 (mod p)
所以a^(p-2)即 a关于质数p模意义下的乘法逆元
当a是p的倍数的时候，余数为0，无解
*/
inline ll qmi(ll a,ll b, ll p){
    ll ans=1%p;
    while(b){
        if(b&1)
            ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
ll res = qmi(a,p-2,p);
if( a % p != 0) //这时无解

