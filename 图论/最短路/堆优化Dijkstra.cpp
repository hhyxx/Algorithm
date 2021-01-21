//2. 堆优化版dijkstra

// O(m * log n) 
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int h[N],dist[N],id;
bool st[N];
int n,m;
struct node{int to,ne,w;}e[N];
void add(int u,int v,int w)
{
    e[++id].to=v;
    e[id].w=w;
    e[id].ne=h[u];
    h[u]=id;
}
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii>>heap;
    heap.push({0,1}); // first存储距离，second存储节点编号
    
    while(heap.size())
    {
        auto t=heap.top();
        heap.pop();
        int ver=t.se,d=t.fi;
        if(st[ver]) continue;
        st[ver]=1;

        for(int i=h[ver];i;i=e[i].ne)
        {
            int to=e[i].to,w=e[i].w;
            if(dist[to] > d+w)
            {
                dist[to] = d+w;
                heap.push({dist[to],to});
            }
        }
    } 
    if(dist[n]==INF) return -1;
    else return dist[n];
}
