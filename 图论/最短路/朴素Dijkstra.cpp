// 朴素dijkstra算法,适用于稠密图即e = v^2，不含负权边

// O(n^2)

const int INF=0x3f3f3f3f;
int g[N][N];// 存储每条边
int dist[N];// 存储1号点到每个点的最短距离// 存储每条边
bool st[N]; // 存储每个点的最短路是否已经确定
int n,m;

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);

    dist[1]=0;
    rep(i,0,n-1) // O(n) 更新n-1次即更新每个点
    {
        int t=-1;

        // O(n) 在还未确定最短路的点中，寻找距离最小的点
        rep(j,1,n) if(!st[j] && (dist[t]>dist[j] || t==-1)) t=j;
        st[t]=1;

        // 总共有O(m) relax操作，用t更新其他点的距离
        rep(j,1,n) dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
    if(dist[n]==INF) return -1;
    return dist[n];
}

