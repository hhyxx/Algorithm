

// 试除法分解质因数
// O（ sqrt(n) ）

vector<pair<int,int>> primes_factors;
void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            primes_factors.push_back{i,s};
        }
    // first 表示素数，second 表示当前的指数
    if (x > 1) primes_factors.push_back{x,1}; 
}

