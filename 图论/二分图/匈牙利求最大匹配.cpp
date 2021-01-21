int n1,n2,m;
int h[N],e[M],ne[M],idx;
bool st[N];
int match[N];
void add(int x,int y){
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
bool find(int x){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(!st[j]){
            st[j]=1;
            if(match[j]==0 || find(match[j])){//要匹配的，还没匹配或但是已经匹配了的，找另一个
                match[j]=x;
                return 1;
            }
        }
    }
    return 0;
}
	
// 求最大匹配数
int ans=0;
rep(i,1,n1+1){
    memset(st,0,sizeof st);
    if(find(i)) ans++;
}