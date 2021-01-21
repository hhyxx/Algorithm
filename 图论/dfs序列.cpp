
//链式前向星
struct Edge{
    int to,w,ne;
}e[N];
void add(int x,int y,int z){
    e[idx++].to=y;
    e[idx].ne[idx]=h[x];
    e[idx].w=z;
    h[x]=idx; 
}



//结构体存边
struct Edge{
    int st,to,w;
    bool operator < (const Edge &W)const{
        return w<W.w;
    }
}edges[M];



//邻接矩阵

g[N][N];
memset(g,0x3f,sizeof g);

