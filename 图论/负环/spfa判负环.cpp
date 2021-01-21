
//原理：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环。

int n,m;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N], cnt[N];        // dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
bool st[N];     // 存储每个点是否在队列中
struct node{int to,ne,w;}e[N];
void add(int u,int v,int w)
{
    e[++id].to=v;
    e[id].ne=h[u];
    e[id].w=w;
    h[u]=id;
}
bool SPFA()
{
    queue<int>q;
    // 不需要初始化dist数组,因为有负权回路就会直接在上面转到点数超过n+1
    // 将所有点加入队列中，一个虚拟源点，初始所有点距离他都是0
    rep(i,1,n) {q.push(i);st[i]=1;}
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];i;i=e[i].ne)
        {
            int to=e[i].to;
            if(dist[to]>dist[t]+e[i].w)
            {
                dist[to]=dist[t]+e[i].w;
                cnt[to]=cnt[t]+1;
                // 经过n条边，n+1个点
                if(cnt[to]>=n) return 1;  
                if(!st[to]) q.push(to),st[to]=1;
            }
        }
    }
    return 0;
}