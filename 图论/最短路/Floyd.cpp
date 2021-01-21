const int INF=0x3f3f3f3f;
int g[N][N];
int dist[N][N];
int n,m,k;
void init()
{
    rep(i,1,n) rep(j,1,n) 
    if(i==j) dist[i][j]=0;
    else dist[i][j]=INF;
}
void floyd()
{
    rep(k,1,n) rep(i,1,n) rep(j,1,n)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

// 最小权值环
void floyd()
{
    int mincycle=INF;
    rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
        dist[i][j]=min(mincycle,dist[i][j]+dist[i][k]+dist[k][j]);
}

void floyd() // 求传递闭包
{
    rep(k,1,n+1) rep(i,1,n+1)
        if(f[i][k]) f[i]=f[i]|f[k];
}