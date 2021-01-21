// 求x, y，使得ax + by = gcd(a, b)，同时求出gcd
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0; // 即a,0 的时候倒推
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;// 回溯的过程中进行计算
    return d;
}

 /*

 对于更一般的方程　ax + by = c ，有解当且仅当 (a,b) | c
 求出ax + by = gcd(a,b)的一组特解 x0,y0
 则 ax + by = c的一组特解就是x'= (c/(a,b))*x0,y'=(c/(a,b))*y0
 通解的表示：k为整数 整数和负数都可以必须是整数
 x=c/(a,b) * x0 + k * b/(a,b)  即所有模b/d与x'同余的整数
 y=c/(a,b) * y0 + k * a/(a,b) 即所有模a/d与y'同余的整数

 */