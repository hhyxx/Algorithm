// 试除法求所有约数
// 一个数n的约数个数的上界为2 * sqrt(n)
// O（ sqrt(n) ）

vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            //大的那一个如果相同只加一个即可
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end()); 
    return res;
}



