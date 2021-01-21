
// 反素数：g(x)表示x的约数个数，对于任意的小于x的i，g(i)<g(x)，x为反素数
// 1~n 中约数个数最多的数值最小的就是最大的反素数

// 试除法判定质数
// O（ sqrt(n) ）
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

