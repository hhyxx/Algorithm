
//线性方程组

double a[MAXN][MAXN];// 最后一列开始存的是方程右边常数，运算后解
// gauss
// O(n^3)
int gauss()
{
	int c, r;
	for (c = 1, r = 1; c <= n; c ++ ){
		int t = r;
		for (int i = r; i <= n; i ++ )
			if (fabs(a[i][c]) > fabs(a[t][c]))//找到当前列最大的行
				t = i;
		if (fabs(a[t][c]) < eps) continue;
		for (int i = c; i <= n + 1; i ++ ) swap(a[t][i], a[r][i]);
		for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];

		for (int i = r + 1; i <= n; i ++ )//后面行这一列变0
			if (fabs(a[i][c]) > eps)
				for (int j = n+1; j >= c; j -- )
					a[i][j] -= a[r][j] * a[i][c];
		r ++ ;
	}
	if (r < n+1){
		for (int i = r; i <= n; i ++ )
			if (fabs(a[i][n+1]) > eps)
				return 2;
		return 1;
	}
	for (int i = n ; i >= 0; i -- )
		for (int j = i + 1; j <= n; j ++ )
			a[i][n] -= a[j][n] * a[i][j];
	return 0;
}


// 异或线性方程组

int a[N][N];
int n;
int gauss(){
    int c,r;
    for (c = 0,r=0; c <n ; ++c) {
        int t=r;
        for (int i = r; i <n ; ++i)
            if(a[i][c])
                t=i;

        if(!a[t][c]) continue;

        for (int i =c; i <=n ; ++i)
            swap(a[t][i],a[r][i]);

        for (int i = r+1; i <n ; ++i) {
            if(a[i][c])
                for (int j = n; j >=c ; j--) {
                    a[i][j]^=a[r][j];
                }
        }
        r++;
    }

    if(r<n){
        for (int i = r; i <n ; ++i)
            if(a[i][n]) return 2;
            return 1;
    }
    for (int i = n-2; i >=0 ; i--)
        for (int j = i+1; j <n ; ++j)
            a[i][n]^=a[i][j]*a[j][n];
    return 0;
}
