// O（nlogn）预处理，O（1）查询最值

void st_pre()
{
    for(int i = 1; i <= n; i++)
        f[i][0]=a[i];
    int t=log(n)/log(2);
    for(int j = 1; j <= t; j ++)
        for(int i = 1; i <= n - (1 << j) + 1; i++)//计算所有起点为i，长度为2^j区间内部的最大值
            f[i][j] = max(f[i][j-1] , f[i + (1 << (j - 1))][j-1]);
}
int ST_query(int l,int r)
{
    int k=log(r-l+1)/log(2);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}