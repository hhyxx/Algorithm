const int N=510;
const int INF=0x3f3f3f3f;

int n;      // n表示点数
int g[N][N];        // 邻接矩阵，存储所有边
int dist[N];        // 存储其他点到当前最小生成树的距离
bool st[N];     // 存储每个点是否已经在生成树中
// 如果图不连通，则返回INF(值是0x3f3f3f3f), 因为不联通所以即使有负权边也不会更新到
int prim()
{
    memset(dist,0x3f,sizeof dist);
    int res=0;
    rep(i,0,n)
    {
        int t=-1;
        rep(j,1,n+1)
            if(!st[j] && (t==-1 || dist[t] > dist[j]))
                t=j;
        st[t]=1;
        if(i && dist[t] == INF) return INF;

        if(i) res += dist[t];
        st[t]=1;
        rep(j,1,n+1)
            dist[j]=min(dist[j],g[t][j]);//和dijkstra的区别
    }
    return res;
}