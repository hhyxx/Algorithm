#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define close ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

const int N=10010,M=300010;
const int INF = 0x7f7f7f7f;

struct edge
{
    int to,c,ne;
}e[M];
int h[N],idx;
int q[N],d[N],cur[N];// 队列、层数、当前弧
int n,m,S,T;

void add(int u,int v,int c)
{
    e[idx].to=v;
    e[idx].c = c;
    e[idx].ne=h[u];
    h[u]=idx++;

    e[idx].to=u;
    e[idx].c=0;
    e[idx].ne=h[v];
    h[v]=idx++;
}

bool bfs()
{
    int hh=0,tt=0;
    memset(d,-1,sizeof d); // 每一次都重新分层
    q[0]=S,d[S]=0,cur[S]=h[S];
    
    while(hh <= tt)
    {
        int now = q[hh++];
        for(int i = h[now]; ~i; i = e[i].ne)
        {
            int to = e[i].to;
            if(d[to] == -1 && e[i].c) // 当前点的层数未更新即未访问
            {
                d[to] = d[now]+1;
                cur[to] =  h[to]; // 当前的弧是这个
                if(to == T) return true;
                q[++tt] = to;
            }
        }
    }
    return false;
}

int find(int u,int limit)
{
    if(u == T) return limit;
    int flow = 0;
    for(int i=cur[u]; ~i && flow < limit ; i = e[i].ne)
    {
        cur[u] = i; // 当前弧优化 , 即当前弧度计算过后，不会再访问这个弧
        int to = e[i].to;
        if(d[to] == d[u] + 1 && e[i].c) // 当前层是从上一层来的，且能够贪心的增加流量
        {
            int tmp= find(to ,min(e[i].c, limit - flow));
            if(!tmp) d[to] =-1;
            e[i].c -= tmp,e[i^1].c += tmp,flow += tmp;
        }
    }
    return flow;
}

int Dinic()
{
    int maxflow = 0,flow;
    while(bfs())
        while(flow = find(S,INF)) // 从源点开始
            maxflow += flow; // 当前有增广路，即可以贪心的增加流量
    return maxflow;
}

int main()
{
    close
    cin>>n>>m>>S>>T;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c);
    }
    cout<<Dinic()<<endl;
    return 0;
}

