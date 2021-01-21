struct node
{
    int u,v,w;
    bool operator < (const node &t)
    {
        return w<t.w;
    }
}e[N*2];
int find(int u)
{
    if(fa[u]==u) return u;
    return fa[u]=find(fa[u]);
}
void merge(int a,int b)
{
    int pa=find(a),pb=find(b);
    fa[pa]=pb;
}
int Kruskal()
{
    sort(e+1,e+1+m);
    int res=0,cnt=0;
    rep(i,1,n+1) fa[i]=i;
    rep(i,1,m+1)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int pa=find(u),pb=find(v);
        if(pa!=pb)
        {
            merge(pa,pb);
            cnt++;
            res+=w;
        }
        if(cnt==n-1) break;
    }
    if(cnt<n-1) return INF;
    else return res;
}