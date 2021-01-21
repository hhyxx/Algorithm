int a[2*N];//每个节点进出一次
int m,n;
bool f[N];
int h[N],e[N],ne[N],w[N],idx;
void add(int x,int y,int z){
    e[idx]=y,w[idx]=z,ne[idx]=h[x],h[x]=idx++;
}
void dfs(int x){
    a[++m]=x;
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(f[j]) continue;
        dfs(j);
    }
    a[++m]=x;
}