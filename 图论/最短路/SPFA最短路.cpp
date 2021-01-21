struct node{int to,ne,w;}e[N];
void add(int u,int v,int w)
{
    e[++id].to=v;
    e[id].ne=h[u];
    e[id].w=w;
    h[u]=id;
}
int SPFA()
{
    queue<int>q;
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    st[1]=1;
    q.push(1);
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=0; // 已经出队
        for(int i=h[t];i;i=e[i].ne)
        {
            int to=e[i].to;
            if(dist[to]>dist[t]+e[i].w)
            {
                dist[to]=dist[t]+e[i].w;
                if(!st[to]) q.push(to),st[to]=1;// 队列已存在to，不需要重复插入
            }
        }
    }
    if(dist[n]==INF) return -1;
    else return dist[n];
}