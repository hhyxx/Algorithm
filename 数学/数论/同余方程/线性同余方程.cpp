/*
 扩展欧几里得算法求解线性同余方程
 即求出 x 满足 a * x ≡ b (mod m)，或者给出无解
    a * x ≡ b (mod m)
 => a * x = m * y +b
 => a * x - m * y = b
 => a * x + m * y = b 
*/
// 线性同余方程有解当且仅当 gcd(a,m) | b
// 特解：x=x0*b/gcd(a,m)
// 通解是所有模m/gcd(a,m)与特解同于的整数
int exgcd(int a,int b,int &x,int &y)
{
  if(!b){
      x=1,y=0;
      return a;
  }
  int d=exgcd(b,a%b,y,x);
  y -= (a/b)*x;
  return d;
}
 /*
 对于更一般的方程　ax + by = c ，设gcd(a,b)=d,有解当且仅当的 d | c
 求出ax + by = gcd(a,b)的一组特解 x0,y0
 则 ax + by = c的一组特解就是x'= (c/d)*x0,y'=(c/d)*y0
 通解的表示：
 x = c/d * x0 + k*b/d
 y = c/d * y0 - k*a/d
 k为整数
 */


/*
 中国剩余定理求线性同余方程组
 m1,m2,......,mk 必须两两互质
 x ≡ a1(mod m1)
 x ≡ a2(mod m2)
 ......
 x ≡ ak(mod mk)

 令 M = m1 * m2 * ...... * mk
 Mi = M / mi 和 mi互质，求出Mi的逆Mi'
 
 通解 x = ∑(i=1:k) ai * Mi * Mi'（需要求出每个Mi的逆

*/
ll CRT()
{
	ll M=1;
	rep(i,1,n+1)  M*=m[i];

	ll res=0;
	rep(i,1,n+1)
    {
		ll x,y;
		ll tmp=M/m[i];
		exgcd(tmp,m[i],x,y);
		res=(res+tmp*x*a[i])%M;
	}
	return ((res+M)%M)%M;
}
// m不是两两互质也可以，每次两个式子合并成一个式子

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
cin>>n;
ll a1,m1;
	cin>>a1>>m1;
	for(int i=0;i<n-1;i++){
		ll a2,m2,k1,k2;
		cin>>a2>>m2;
		ll d=exgcd(a1,a2,k1,k2);//式子中的a2系数当作整数传入，得到的k可能为负数
		if((m2-m1)%d) {puts("-1");return 0;}
		k1*=(m2-m1)/d;//由裴蜀定理的解转化为方程解
		ll t=(a2/d);
		k1=(k1%t+t)%t;//对负数取模
		m1=k1*a1+m1;
		a1=a1/d*a2;
	}
cout<<(m1%a1+a1)%a1<<endl;