// 查询 插入都是 O（nlogn）
int lowbit(int x) 
{
   return x & -x;
}

void add(int x, int y) 
{
   for (int i = x; i <= n; i += lowbit(i)) 
    c[i] += y;
}

int ask(int x) 
{
   int res = 0;
   for (int i = x; i; i -= lowbit(i)) 
    res += c[i];
   return res;
}