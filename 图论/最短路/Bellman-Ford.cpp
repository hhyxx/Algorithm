// 可以求存在负权边图的最短路
const int INF=0x3f3f3f3f;
struct node{int u,v,w;}e[M];
int n,m,k;
int dist[N];

bool bellman()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    rep(i,1,n-1) // n-1次
    {
    	bool update=0;
        rep(i,1,m+1) // 遍历每条边
        {
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(dist[v] > dist[u]+w)
            {
            	dist[v]=dist[u]+w;
            	update=1;
            }
        }
        // 已经不会再进行松弛操作了，所以不会存在负权回路
        // 本次没有更新，下次也不会更新
        if(!update) return 1;
    }
    if(dist[n]>INF/2) return -1; 
    else return dist[n];
}

