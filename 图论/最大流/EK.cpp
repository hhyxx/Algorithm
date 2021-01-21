#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define close ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

const int N=1010,M=20010;
const int INF = 0x7f7f7f7f;

struct edge
{
    int to,c,ne;
}e[M];

int h[N],idx;
int q[N];
int d[N];  // 访问该点时当前所有边容量的最小值
int pre[N]; // 此节点上一个节点编号
bool st[N];

int n,m,s,t;

void add(int u,int v,int c)
{
    e[idx].to = v;
    e[idx].c = c;
    e[idx].ne=h[u];
    h[u]=idx++;

    e[idx].to = u; // 建立反向边
    e[idx].c = 0;
    e[idx].ne=h[v];
    h[v]=idx++;
}
bool bfs()
{
    int hh=0,tt=0;
    memset(st,0,sizeof st);
    q[0] = s,st[s] = true,d[s] = INF; // 源点
    while(hh <= tt)
    {
        int tmp = q[hh++];
        for(int i = h[tmp];~i;i=e[i].ne)
        {
            int to = e[i].to;
            if(!st[to] && e[i].c) // 当前点没有被遍历过并且有剩余的流量
            {
                st[to] = true;
                d[to] = min(d[tmp] , e[i].c); // 流量等于当前增广路的最小值
                pre[to] = i;
                if(to == t) return true; // 到达汇点，即一条增广路径
                q[++tt] = to;
            }
        }
    }
    return false;
}
int EK()
{
    int maxf = 0;
    while( bfs() )
    { 
        maxf += d[t];
        for (int i = t; i != s; i = e[pre[i]^1].to) //通过反向边找到这条边的起点
        {
            // 每条边是以出点保存的，所以减要从出点减
            e[ pre[i] ].c -= d[t]; // 当前增广路径上加上残留的流量后，容量减少
            e[ pre[i]^1 ].c += d[t];// 反向边的容量表示可以减少的值，对应增加
        }
    }
    return maxf;
}

int main()
{
    close
    cin>>n>>m>>s>>t;
    memset(h,-1,sizeof h);

    while(m--)
    {
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c);
    }

    cout<<EK()<<endl;
    return 0;
}
